"""Report decomp completion: matched functions / bytes vs the whole game.

Totals come from the dsd config (every kind:function across all modules).
Matched functions are recorded in progress/matched.jsonl (one JSON object per
line: {"addr","name","size","module","versions"}). De-duped by addr.

Usage:
    python tools/progress.py
"""
import json
import pathlib
import re

REPO = pathlib.Path(__file__).resolve().parent.parent
CONFIG = REPO / "config"
MATCHED = REPO / "progress" / "matched.jsonl"

FUNC_RE = re.compile(r"kind:function\((?:arm|thumb),size=0x([0-9a-fA-F]+)\)")


def totals():
    n = 0
    total_bytes = 0
    per_module = {}
    for sym in CONFIG.rglob("symbols.txt"):
        # module label: e.g. arm9, arm9/itcm, arm9/overlays/ov006
        mod = sym.parent.relative_to(CONFIG).as_posix()
        m_n = m_b = 0
        for line in sym.read_text(errors="ignore").splitlines():
            mm = FUNC_RE.search(line)
            if mm:
                sz = int(mm.group(1), 16)
                m_n += 1
                m_b += sz
        if m_n:
            per_module[mod] = (m_n, m_b)
            n += m_n
            total_bytes += m_b
    return n, total_bytes, per_module


def matched():
    if not MATCHED.is_file():
        return {}
    seen = {}
    for line in MATCHED.read_text(errors="ignore").splitlines():
        line = line.strip()
        if not line:
            continue
        try:
            o = json.loads(line)
            seen[int(o["addr"], 0) if isinstance(o["addr"], str) else o["addr"]] = o
        except Exception:
            continue
    return seen


def main():
    n, tb, per = totals()
    done = matched()
    done_n = len(done)
    done_b = sum(int(o.get("size", 0)) for o in done.values())
    print("=== SM64DS decomp progress ===")
    print(f"  functions : {done_n:,} / {n:,}  ({100*done_n/n:.4f}%)")
    print(f"  code bytes: {done_b:,} / {tb:,}  ({100*done_b/tb:.4f}%)")
    print(f"  modules with code: {len(per)}")
    # biggest modules, to show where the mass is
    top = sorted(per.items(), key=lambda kv: kv[1][1], reverse=True)[:6]
    print("  largest modules (by bytes):")
    for mod, (mn, mb) in top:
        print(f"    {mod:28} {mn:5} funcs  {mb:>9,} bytes")


if __name__ == "__main__":
    main()
