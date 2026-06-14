"""Ingest a grind-batch workflow result: write matched C to src/, record progress,
accumulate findings. Robust for unattended overnight cycles.

- Maps each matched result to a target by NAME, consuming addresses so duplicate
  symbol names (e.g. two _ZN5SceneD0Ev) each get their own record.
- Writes src/<name>.c (collision-safe: appends _<addr> on repeat names).
- Appends progress/matched.jsonl keyed by addr (dedup).
- Appends agent findings to knowledge/findings-grind.md.

Usage:
    python tools/ingest_batch.py --output <task.output> --targets match/targets_cluster.json
"""
import argparse
import collections
import json
import pathlib

REPO = pathlib.Path(__file__).resolve().parent.parent
SRC = REPO / "src"
MATCHED = REPO / "progress" / "matched.jsonl"
FINDINGS = REPO / "knowledge" / "findings-grind.md"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--output", required=True)
    ap.add_argument("--targets", required=True)
    args = ap.parse_args()

    out = json.loads(pathlib.Path(args.output).read_text(encoding="utf-8", errors="ignore"))
    result = out.get("result", out)
    matched = result.get("matched", [])
    failed = result.get("failed", [])

    byname = collections.defaultdict(list)
    for t in json.loads(pathlib.Path(args.targets).read_text()):
        byname[t["name"]].append(t)

    existing = set()
    if MATCHED.is_file():
        for line in MATCHED.read_text(errors="ignore").splitlines():
            line = line.strip()
            if line:
                try:
                    existing.add(json.loads(line)["addr"])
                except Exception:
                    pass

    SRC.mkdir(exist_ok=True)
    written, added, fd = set(), 0, []
    with MATCHED.open("a", encoding="utf-8") as log:
        for m in matched:
            name = m.get("name", "")
            pool = byname.get(name)
            t = pool.pop(0) if pool else {}
            addr = t.get("addr") or ("0x" + name.split("_")[1] if "_" in name else "0x0")
            size = t.get("size", 0)
            fn = f"{name}.c" if name not in written else f"{name}_{addr}.c"
            written.add(name)
            try:
                (SRC / fn).write_text(m.get("c_source", ""), encoding="utf-8")
            except Exception as e:
                print(f"  ! could not write src/{fn}: {e}")
            if m.get("findings", "").strip():
                fd.append(f"### {name} ({addr})\n{m['findings']}")
            if addr in existing:
                continue
            log.write(json.dumps({"addr": addr, "name": name, "size": size,
                                  "module": "arm9", "versions": m.get("versions", [])}) + "\n")
            existing.add(addr)
            added += 1

    if fd:
        with FINDINGS.open("a", encoding="utf-8") as f:
            f.write(f"\n\n## batch {pathlib.Path(args.output).stem}\n\n" + "\n\n".join(fd))

    # Auto-skip: count failures; a function that fails twice gets added to skip.txt
    # so the selector stops recirculating known-hard functions.
    try:
        fc_path = REPO / "progress" / "fail-counts.json"
        counts = json.loads(fc_path.read_text()) if fc_path.is_file() else {}
        skip_path = REPO / "progress" / "skip.txt"
        skip_txt = skip_path.read_text(errors="ignore") if skip_path.is_file() else ""
        new_skips = []
        for f in failed:
            name = f.get("name", "")
            pool = byname.get(name)
            addr = (pool.pop(0)["addr"] if pool else None)
            if not addr:
                continue
            counts[addr] = counts.get(addr, 0) + 1
            if counts[addr] >= 2 and addr not in skip_txt:
                new_skips.append(addr)
        fc_path.write_text(json.dumps(counts))
        if new_skips:
            with skip_path.open("a", encoding="utf-8") as sf:
                for a in new_skips:
                    sf.write(f"{a}   # auto-skip: failed 2x\n")
            print(f"  auto-skipped {len(new_skips)} repeat-fail functions")
    except Exception as e:
        print(f"  ! fail-tracking skipped: {e}")

    total = len(matched) + len(failed)
    rate = f"{round(100*len(matched)/total)}%" if total else "n/a"
    print(f"matched {len(matched)}/{total} ({rate}); +{added} new records; "
          f"{len(failed)} failed")


if __name__ == "__main__":
    main()
