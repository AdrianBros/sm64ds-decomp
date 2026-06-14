// func_02007fcc @ 0x02007fcc (Camera member, size 0x3c)
// Reads two unaligned ints (val0 @ +0, val1 @ +4) out of the pointer param via
// the "read unaligned u32" helper at 0x0200e728, then lerps the camera's
// field_0x170 (Camera::unk170) toward val0 with step val1, and returns 1.

typedef int Fix12i;

typedef struct Camera {
    char _pad0[0x170];
    Fix12i unk170;      // 0x170
} Camera;

extern int ReadUnalignedInt(const void* p);          // 0x0200e728
extern void ApproachLinear(int* val, int target, int step); // 0x0203ae58

int func_02007fcc(Camera* self, const char* src) {
    int target = ReadUnalignedInt(src);
    int step = ReadUnalignedInt(src + 4);
    ApproachLinear(&self->unk170, target, step);
    return 1;
}
