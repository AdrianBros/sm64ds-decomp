typedef struct { int x, y, z; } Vec3;

struct Actor {
    char pad0[0xb0];
    Vec3 unkB0;     /* 0xb0 */
    int unkBC;      /* 0xbc */
    int unkC0;      /* 0xc0 */
    int unkC4;      /* 0xc4 */
};

extern int func_02007cec(void *dest, Vec3 *src, int n);
extern void ApproachLinear(int *val, int target, int step);

extern const Vec3 data_02086ed8;

int func_020073a0(struct Actor *actor) {
    Vec3 v;
    v.x = data_02086ed8.x;
    v.y = data_02086ed8.y;
    v.z = data_02086ed8.z;
    func_02007cec(&actor->unkB0, &v, 0xcc);
    ApproachLinear(&actor->unkC0, 0, 0x2000);
    ApproachLinear(&actor->unkC4, -0xc8000, 0x6aaa);
    return 1;
}
