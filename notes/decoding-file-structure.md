# Decoding file structure: the source ↔ ROM map

Per-TU header essays used to paste ROM addresses, vtable locations, and
shard tables into every source file. That information now lives in
machine-checked files, and this note is the map to it. The rule: prose
here describes the *system*; concrete addresses live in `config/` and
are verified by the build, so they are never copied into docs or
headers.

## Source file → ROM range

[delinks.txt](../config/arm9/overlays/ov002/delinks.txt) enrolls each
source file as one `complete` span (one object emits one contiguous
`.text`):

    grep -A2 "src/game/actors/d_a_tree.cpp" config/arm9/overlays/ov002/delinks.txt

## ROM address → source file

There is no lookup tool; scan the owning overlay's `delinks.txt` for
the span containing the address:

    python3 -c "
    import re
    addr = 0x020ec100
    cur = None
    for ln in open('config/arm9/overlays/ov002/delinks.txt'):
        m = re.match(r'^(\S+):$', ln)
        if m:
            cur = m.group(1)
            continue
        m = re.search(r'start:(0x[0-9a-f]+)\s+end:(0x[0-9a-f]+)', ln)
        if m and cur and int(m.group(1), 16) <= addr < int(m.group(2), 16):
            print(cur, ln.strip())
    "

## Function → ordinal and legacy shard

The old `[N] address file` header tables are the TU manifest rows:
`ordinal` + `address` + `legacy_source` per function, e.g.
[ov002/daTree_c.json](../config/tu_manifest.d/ov002/daTree_c.json).
The resync gate keeps compiler-numbered symbols in these rows honest.

## VTables, RTTI, type strings

[symbols.txt](../config/arm9/overlays/ov002/symbols.txt) carries one
row per `_ZTV*` / `_ZTI*` / `_ZTS*` with its address.
[actor-vtables.md](actor-vtables.md) explains how to read them
(address point, slot 0, base inference):

    grep "_ZTV8daTree_c" config/arm9/overlays/ov002/symbols.txt

## Slot numbers

Shared headers annotate every virtual with `/* slot N */`
([dActor_c.h](../include/dActor_c.h) is complete through slot 30); a
derived class's new virtuals append after its base's last slot. The
vtable bytes themselves are verified by the build, which is what pins
the annotations.

## Symbol → defining file

Sources carry `// @symbol` markers above each function, backed by the
same TU manifests:

    grep -rn "@symbol _ZN8daTree_c6RenderEv" src/

## Class size

The TU's `classInit` factory carries the measured allocation size as
a literal (`return new` forms) — that literal, not a comment, is the
size evidence.

## History: merged shards, coined names

`git log --follow` on the TU file. What used to be "assembled from"
tables and "the decomp used to call it X" notes is commit history.
