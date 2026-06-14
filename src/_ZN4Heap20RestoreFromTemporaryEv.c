// Heap::RestoreFromTemporary: sets default heap to tmpHeapPtr and resets tmpHeapPtr to null

typedef void Heap;

extern Heap* _ZN6Memory14defaultHeapPtrE;
extern Heap* _ZN6Memory10tmpHeapPtrE;

extern Heap* _ZN4Heap10SetDefaultEv(Heap* self);

void _ZN4Heap20RestoreFromTemporaryEv(void) {
    _ZN4Heap10SetDefaultEv(_ZN6Memory10tmpHeapPtrE);
    _ZN6Memory10tmpHeapPtrE = (Heap*)0;
}
