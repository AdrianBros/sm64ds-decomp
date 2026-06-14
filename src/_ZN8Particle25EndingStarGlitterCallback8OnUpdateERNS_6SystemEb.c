typedef signed int s32;
typedef unsigned int u32;
typedef int Bool;

/* forward declarations */
extern void func_02022260(void);

extern int _ZN8Particle14SimpleCallback8OnUpdateERNS_6SystemEb(void* cb, void* sys, Bool active);

extern void func_0204dab4(void* sys, void* buf, u32 count, u32 mask, void* fnptr);

int _ZN8Particle25EndingStarGlitterCallback8OnUpdateERNS_6SystemEb(void* cb, void* sys, Bool active)
{
    func_0204dab4(sys, (char*)cb + 8, 0x40, 0, (void*)func_02022260);
    return _ZN8Particle14SimpleCallback8OnUpdateERNS_6SystemEb(cb, sys, active);
}
