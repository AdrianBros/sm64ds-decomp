# sm64ds-decomp

A from-scratch effort to decompile **Super Mario 64 DS** into matching C.

## What "matching" means

The goal is source code that, when compiled with the *original toolchain*, produces
a binary **byte-for-byte identical** to the retail ROM. That's the bar real decomp
projects hold to (see the N64 `sm64` project). Anything less is "C that looks right";
matching is C that *is* right.

## Legal / scope

This repo contains **only original work**: our scripts, our hand-written C, our notes.
It contains **no ROM and no extracted Nintendo assets** — those are read locally from a
cartridge dump the user owns, and are git-ignored. Don't commit anything derived from
the ROM's data/assets.

## Layout

| Dir         | Holds                                                        |
|-------------|-------------------------------------------------------------|
| `tools/`    | our Python scripts (unpack ROM, disassemble, diff)          |
| `asm/`      | working disassembly listings (scratch; gitignored for now)  |
| `src/`      | hand-written matching C                                      |
| `include/`  | headers / type definitions we reconstruct                   |
| `extracted/`| ROM unpack output — **local only, gitignored**              |
| `notes/`    | findings: memory map, struct layouts, function index        |

## Status

- [x] Repo scaffolded
- [ ] Toolchain: `ndspy`, `capstone` (Python) — ROM unpack + disassembly
- [ ] Milestone 1: unpack ROM, identify ARM9 + overlays, dump first real functions
- [ ] Milestone 2: identify the original compiler (critical for matching)
- [ ] Milestone 3: first byte-matching function, end to end

## Workflow (the loop)

1. Unpack ROM -> ARM9 / ARM7 / overlays / filesystem (`tools/unpack.py`)
2. Disassemble a region to ARM (`tools/disasm.py`)
3. Hand-write C for one function
4. Compile with the matching toolchain, diff bytes against the ROM
5. Iterate until identical, then move to the next function
