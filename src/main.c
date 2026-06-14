/* main @ 0x02007000 (size 0x5c) — system init sequence.
 * Calls two setup routines, configures two global subsystems, then
 * tags the root heap with node IDs around another setup step. */

typedef unsigned int u32;

/* Heap (only the SetNodeID member is needed). */
typedef struct Heap Heap;
extern void _ZN4Heap9SetNodeIDEj(Heap *heap, u32 id); /* Heap::SetNodeID */

/* Root heap pointer (Memory::rootHeapPtr). */
extern Heap *_ZN6Memory11rootHeapPtrE;

/* Setup routines (names not in the verified map). */
extern void func_02059788(void);
extern void func_02059bc0(void);
extern void func_02059578(void *a, void *b);
extern void func_0201a054(void);
extern void func_020197b8(void);

/* Globals passed to func_02059578. */
extern void *data_0201a03c;
extern void *data_020a621c;

void main(void)
{
    func_02059788();
    func_02059bc0();
    func_02059578(&data_0201a03c, &data_020a621c);
    _ZN4Heap9SetNodeIDEj(_ZN6Memory11rootHeapPtrE, 2);
    func_0201a054();
    _ZN4Heap9SetNodeIDEj(_ZN6Memory11rootHeapPtrE, 3);
    func_020197b8();
}
