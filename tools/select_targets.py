"""Select small ARM9-main functions as decomp targets, newest grind first.

Picks kind:function entries from config/arm9/symbols.txt within a size range that
live inside the decompressed arm9 image (so disasm offsets are valid), skips ones
already in progress/matched.jsonl, and prints a JSON array of targets.

Usage:
    python tools/select_targets.py [--min 0x10] [--max 0x30] [--count 30]
"""
import argparse
import json
import pathlib
import re

REPO = pathlib.Path(__file__).resolve().parent.parent
SYMS = REPO / "config" / "arm9" / "symbols.txt"
ARM9 = REPO / "extracted" / "arm9_dec.bin"
MATCHED = REPO / "progress" / "matched.jsonl"
BASE = 0x02004000

LINE_RE = re.compile(r"^(\S+)\s+kind:function\((arm|thumb),size=0x([0-9a-fA-F]+)\)\s+addr:0x([0-9a-fA-F]+)")


def already():
    done = set()
    if MATCHED.is_file():
        for line in MATCHED.read_text(errors="ignore").splitlines():
            line = line.strip()
            if line:
                try:
                    done.add(int(json.loads(line)["addr"], 0))
                except Exception:
                    pass
    return done


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--min", type=lambda x: int(x, 0), default=0x10)
    ap.add_argument("--max", type=lambda x: int(x, 0), default=0x30)
    ap.add_argument("--count", type=int, default=30)
    ap.add_argument("--mode", default="arm", choices=["arm", "thumb", "any"])
    ap.add_argument("--lo", type=lambda x: int(x, 0), default=BASE, help="min address")
    ap.add_argument("--hi", type=lambda x: int(x, 0), default=0xFFFFFFFF, help="max address")
    args = ap.parse_args()

    done = already()
    limit = BASE + ARM9.stat().st_size
    out = []
    for line in SYMS.read_text(errors="ignore").splitlines():
        m = LINE_RE.match(line)
        if not m:
            continue
        name, mode, size_hex, addr_hex = m.group(1), m.group(2), m.group(3), m.group(4)
        size = int(size_hex, 16)
        addr = int(addr_hex, 16)
        if args.mode != "any" and mode != args.mode:
            continue
        if not (args.min <= size <= args.max):
            continue
        if not (BASE <= addr < limit):
            continue
        if not (args.lo <= addr < args.hi):
            continue
        if addr in done:
            continue
        out.append({"name": name, "addr": f"0x{addr:08x}", "size": size,
                    "mode": mode, "offset": f"0x{addr - BASE:x}"})
        if len(out) >= args.count:
            break
    print(json.dumps(out, indent=2))


if __name__ == "__main__":
    main()
