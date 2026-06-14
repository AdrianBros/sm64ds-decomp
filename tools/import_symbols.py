"""Import verified symbol names from an external symbols.x into our dsd config.

Source: SplattyDS/DynamicAllocationDecomp `symbols.x` (EU, same build as our ROM;
71.9% of its addresses land on dsd-found function starts). We import only the NAMES
(facts/interface), never their source code. Names are credited in CREDITS.md.

Conservative rules:
  - A symbol becomes a FUNCTION name only if its address is an exact function-start
    in our analysis; otherwise it's recorded as a DATA symbol.
  - We only rename dsd functions still called `func_<addr>` (never clobber names dsd
    already assigned, e.g. SDK signatures).
  - C++/namespace names are sanitized to valid identifiers.

Writes:
  - config/**/symbols.txt   (function renames, in place)
  - symbols/verified.tsv    (addr<TAB>name<TAB>kind  -- the artifact we own)

Usage:  python tools/import_symbols.py [--apply]
"""
import argparse
import pathlib
import re

REPO = pathlib.Path(__file__).resolve().parent.parent
# Symbol sources, most-complete first (first name to claim an address wins).
SOURCES = [
    REPO / "reference" / "DynamicAllocationDecomp" / "symbols.x",
    REPO / "reference" / "SM64DS-ASM-Reference" / "symbols.x",
    REPO / "reference" / "MoreObjectsMod" / "ASM" / "symbols.x",
    REPO / "reference" / "MoreObjectsMod" / "ASM_HouseKeeper" / "symbols.x",
]
CONFIG = REPO / "config"
OUT = REPO / "symbols" / "verified.tsv"


def sanitize(name: str) -> str:
    name = name.replace("::", "__")
    name = re.sub(r"[^A-Za-z0-9_]", "_", name)
    return name


def our_function_starts():
    starts = {}
    for sym in CONFIG.rglob("symbols.txt"):
        for line in sym.read_text(errors="ignore").splitlines():
            m = re.search(r"^(\S+)\s+kind:function\(.*?\)\s+addr:0x([0-9a-fA-F]+)", line)
            if m:
                starts[int(m.group(2), 16)] = (sym, m.group(1))
    return starts


def parse_symbols_x():
    out = {}  # addr -> canonical name (first source/first line wins; aliases dropped)
    for src in SOURCES:
        if not src.is_file():
            continue
        nocomment = re.sub(r"/\*.*?\*/", "", src.read_text(errors="ignore"), flags=re.S)
        for m in re.finditer(r"([A-Za-z_][\w:]*)\s*=\s*0x0?([0-9a-fA-F]{6,8})\s*;", nocomment):
            out.setdefault(int(m.group(2), 16), sanitize(m.group(1)))
    return out


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true", help="write renames into config (else dry run)")
    args = ap.parse_args()

    starts = our_function_starts()
    theirs = parse_symbols_x()

    funcs, data = {}, {}
    for addr, name in theirs.items():
        if addr in starts:
            funcs[addr] = name
        else:
            data[addr] = name

    # Build per-file rename plan: only slots still named func_<addr>.
    renamable = 0
    plan = {}  # file -> list of (old, new)
    for addr, newname in funcs.items():
        sym_file, cur = starts[addr]
        if cur.startswith("func_"):
            plan.setdefault(sym_file, []).append((cur, newname))
            renamable += 1

    print(f"their active symbols: {len(theirs)}")
    print(f"  -> function names (addr is a function-start): {len(funcs)}")
    print(f"  -> data symbols:                              {len(data)}")
    print(f"renamable now (currently func_*):               {renamable}")

    OUT.parent.mkdir(exist_ok=True)
    with OUT.open("w", encoding="utf-8") as f:
        for addr in sorted(theirs):
            kind = "function" if addr in funcs else "data"
            f.write(f"0x{addr:08x}\t{theirs[addr]}\t{kind}\n")
    print(f"wrote {OUT.relative_to(REPO)} ({len(theirs)} symbols)")

    if not args.apply:
        print("\n(dry run) re-run with --apply to write function renames into config/")
        return

    total = 0
    for sym_file, pairs in plan.items():
        text = sym_file.read_text(errors="ignore")
        for old, new in pairs:
            text = re.sub(rf"^{re.escape(old)}\b", new, text, count=1, flags=re.M)
            total += 1
        sym_file.write_text(text, encoding="utf-8")
    print(f"applied {total} function renames across {len(plan)} module symbol files")


if __name__ == "__main__":
    main()
