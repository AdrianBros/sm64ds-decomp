struct Stage { void **vtable; };
struct Heap;
extern void *_ZTV5Stage[];
extern void *_ZTV5Scene[];
extern void *_ZTV12ActorDerived[];
extern void _ZN12MeshColliderD1Ev(void *thiz);
extern void _ZN5ModelD1Ev(void *thiz);
extern void _ZN8Particle10SysTrackerD1Ev(void *thiz);
extern void _ZN9ActorBaseD1Ev(struct Stage *thiz);
extern void _ZN6Memory10DeallocateEPvP4Heap(void *ptr, struct Heap *heap);
extern struct Heap *_ZN6Memory11gameHeapPtrE;

struct Stage *_ZN5StageD0Ev(struct Stage *thiz)
{
    thiz->vtable = (void **)_ZTV5Stage;
    _ZN12MeshColliderD1Ev((char *)thiz + 0x91c);
    _ZN5ModelD1Ev((char *)thiz + 0x86c);
    _ZN8Particle10SysTrackerD1Ev((char *)thiz + 0x50);
    thiz->vtable = (void **)_ZTV5Scene;
    thiz->vtable = (void **)_ZTV12ActorDerived;
    _ZN9ActorBaseD1Ev(thiz);
    _ZN6Memory10DeallocateEPvP4Heap(thiz, _ZN6Memory11gameHeapPtrE);
    return thiz;
}
