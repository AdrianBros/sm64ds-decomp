/* func_020094e4 @ 0x020094e4, size 0x5c, ARM.
 * Camera state-entry helper: selects camera setting 0x1f (func_0200cb58),
 * then positions the camera by rotating a fixed offset vector by the owner's
 * yaw and translating by the camera's stored owner position, writing the
 * result into the camera position. Returns 1.
 */

typedef int Fix12i; /* 20.12 fixed point */

typedef struct Vector3 {
    Fix12i x, y, z;
} Vector3;

typedef struct Vector3_16 {
    short x, y, z;
} Vector3_16;

typedef struct Actor {
    char _pad0[0x8c];
    Vector3_16 ang;      /* 0x8c (ang.y @ 0x8e) */
} Actor;

typedef struct Camera {
    char _pad0[0x8c];
    Vector3 pos;         /* 0x8c */
    Vector3 ownerPos;    /* 0x98 */
    char _pad1[0x110 - 0xa4];
    Actor *owner;        /* 0x110 */
} Camera;

extern const Vector3 _src_020094e4;   /* global offset vector @ 0x02086eb4 */

extern void func_0200cb58(Camera *cam, int index);
extern void Vec3_RotateYAndTranslate(Vector3 *res, const Vector3 *trans,
                                     short angY, const Vector3 *v);

int func_020094e4(Camera *cam) {
    Vector3 v;

    func_0200cb58(cam, 0x1f);
    v.x = _src_020094e4.x;
    v.y = _src_020094e4.y;
    v.z = _src_020094e4.z;
    Vec3_RotateYAndTranslate(&cam->pos, &cam->ownerPos, cam->owner->ang.y, &v);
    return 1;
}
