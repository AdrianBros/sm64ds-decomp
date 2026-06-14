// func_0200762c @ 0x0200762c (size 0x6c) - Camera member function.
// Sets Camera->savedLookAt by rotating a fixed offset vector by the owner
// actor's yaw (+0x8000, i.e. facing opposite the player) and translating by
// the owner's position; then clamps savedLookAt.y to a constant height.

typedef int Fix12i; // 20.12 fixed point

typedef struct Vector3 {
    Fix12i x, y, z;
} Vector3;

typedef struct Vector3_16 {
    short x, y, z;
} Vector3_16;

// Owner actor: only the fields this function touches.
typedef struct Actor {
    char _pad0[0x5c];
    Vector3 pos;        // 0x5c
    char _pad1[0x8c - (0x5c + 0xc)];
    Vector3_16 ang;     // 0x8c
} Actor;

// Camera: only the fields this function touches.
typedef struct Camera {
    char _pad0[0xb0];
    Vector3 savedLookAt; // 0xb0
    char _pad1[0x110 - (0xb0 + 0xc)];
    Actor *owner;        // 0x110
} Camera;

extern const Vector3 _src_0200762c; // global offset vector @ 0x02086ec0

extern void Vec3_RotateYAndTranslate(Vector3 *res, const Vector3 *translation,
                                     short angY, const Vector3 *v);

int func_0200762c(Camera *self) {
    Vector3 v;
    v.x = _src_0200762c.x;
    v.y = _src_0200762c.y;
    v.z = _src_0200762c.z;
    Vec3_RotateYAndTranslate(&self->savedLookAt, &self->owner->pos,
                             self->owner->ang.y + 0x8000, &v);
    self->savedLookAt.y = 0x1c9000;
    return 1;
}
