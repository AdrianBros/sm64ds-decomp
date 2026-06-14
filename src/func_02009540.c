typedef int Fix12i;
typedef struct { Fix12i x, y, z; } Vector3;
typedef short s16;

struct Camera {
    char pad0[0x11c];
    Vector3 *ptr_0x11c;   /* 0x11c */
    Vector3 vec_0x120;    /* 0x120 */
    char pad1[0x186 - 0x12c];
    s16 ang_0x186;        /* 0x186 */
};

extern int func_020091f8(struct Camera *cam, Vector3 *v, s16 ang, int flag);
extern void Vec3_RotateYAndTranslate(Vector3 *res, const Vector3 *translation, s16 angY, const Vector3 *v);
extern void ApproachLinear(Vector3 *pos, const Vector3 *dest, Fix12i step);
extern int func_02009138(struct Camera *cam, int arg);

extern const Vector3 data_02086ea8;

int func_02009540(struct Camera *cam) {
    Vector3 res;
    Vector3 v;
    func_020091f8(cam, &cam->vec_0x120, cam->ang_0x186, 0);
    v.x = data_02086ea8.x;
    v.y = data_02086ea8.y;
    v.z = data_02086ea8.z;
    Vec3_RotateYAndTranslate(&res, cam->ptr_0x11c, cam->ang_0x186, &v);
    ApproachLinear(&cam->vec_0x120, &res, 0x8000);
    func_02009138(cam, 0x300000);
    return 1;
}
