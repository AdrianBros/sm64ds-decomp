// NONMATCHING: stack frame/regalloc; Lsl src schedule and c in r4 vs r7 (div~=92)
struct Mtx43 { int m[12]; };
struct V3 { int x, y, z; };

extern void func_0200d8c8(void* cam, void* v, int strength);
extern void MulMat4x3Mat4x3(void* dst, void* a, void* b);
extern void Vec3_Lsl(void* d, void* s, int sh);
extern void _ZN5Actor17HugeLandingDustAtER7Vector3b(void* self, void* v, int b);
extern void Matrix4x3_FromRotationY(void* m, short angle);
extern void MulVec3Mat4x3(void* in, void* m, void* out);
extern void _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(unsigned int id, int x, int y, int z);
extern void* data_0209f318;
extern struct Mtx43 data_020a0e68;
extern char data_ov073_02123360;
extern char data_ov073_021233c0;
extern char data_ov073_021233f0;

void func_ov073_0211f2c0(char* c, int strength)
{
    struct V3 src;
    struct V3 pv;
    struct V3 in;
    struct V3 res;
    struct V3 out;
    struct V3 dv;
    void* anim;
    int x, y, z;
    int mx, my, mz;

    func_0200d8c8(data_0209f318, c + 0x5c, strength);

    data_020a0e68 = *(struct Mtx43*)(c + 0x328);
    MulMat4x3Mat4x3(
        (char*)*(void**)(c + 0x320) + *(int*)(c + 0x4bc) * 0x30,
        &data_020a0e68,
        &data_020a0e68);

    {
        int* p = (int*)(((int)c + 0x4bc) & 0xFFFFFFFFFFFFFFFF);
        *p = *p ^ 1;
    }

    my = data_020a0e68.m[10];
    mx = data_020a0e68.m[9];
    src.y = my;
    mz = data_020a0e68.m[11];
    src.z = mz;
    src.x = mx;
    Vec3_Lsl(&out, &src, 3);

    x = out.x;
    y = out.y;
    z = out.z;
    src.x = x;
    src.y = y;
    src.z = z;

    anim = *(void**)(c + 0x37c);
    if (anim == &data_ov073_02123360) {
        dv.x = x;
        dv.y = y;
        dv.z = z;
        _ZN5Actor17HugeLandingDustAtER7Vector3b(c, &dv, 1);
        return;
    }

    pv.x = *(int*)(c + 0x5c);
    pv.y = *(int*)(c + 0x60);
    pv.z = *(int*)(c + 0x64);

    anim = *(void**)(c + 0x37c);
    if (anim != &data_ov073_021233c0) {
        if (anim != &data_ov073_021233f0)
            goto spawn;
    }
    /* matrix offset for 233c0 and 233f0 */
    in.z = 0;
    in.z = -0xe6000;
    in.x = 0;
    in.y = 0;
    res.x = 0;
    res.y = 0;
    res.z = 0;
    Matrix4x3_FromRotationY(&data_020a0e68, *(short*)(c + 0x8e));
    MulVec3Mat4x3(&in, &data_020a0e68, &res);
    pv.x = pv.x + res.x;
    pv.z = pv.z + res.z;
spawn:
    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x88, pv.x, pv.y, pv.z);
    _ZN8Particle6System9NewSimpleEj5Fix12IiES2_S2_(0x89, pv.x, pv.y, pv.z);
}
