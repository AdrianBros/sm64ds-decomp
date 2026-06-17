extern void* _ZN9ActorBasenwEj(unsigned int size);
extern void _ZN8PlatformC2Ev(void *p);
extern void _ZN12WithMeshClsnC1Ev(void *p);
extern void _ZN25MovingCylinderClsnWithPosC1Ev(void *p);
extern void _ZN7PathPtrC1Ev(void *p);
extern int data_ov092_021322d0[];

int* func_ov092_02132018(void) {
    int *p = (int*)_ZN9ActorBasenwEj(0x594);
    if (p) {
        _ZN8PlatformC2Ev(p);
        *(int**)p = data_ov092_021322d0;
        _ZN12WithMeshClsnC1Ev((char*)p + 0x324);
        _ZN25MovingCylinderClsnWithPosC1Ev((char*)p + 0x4e8);
        _ZN7PathPtrC1Ev((char*)p + 0x58c);
    }
    return p;
}
