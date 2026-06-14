// func_020080f0 @ 0x020080f0 (Camera member, size 0x5c)
// Looks up object 0x13 via func_0200e55c, takes its sub-object at +0x5c, reads
// that sub-object's field at +4, then approaches the camera's pos.y (0x90) and
// lookAt.y (0x84) toward (base + 0x23000) and (base + 0x7d000) respectively,
// with steps 0x51 / 0x266 and an unbounded maxDelta (0x7fffffff). Returns 1.

typedef int Fix12i;

typedef struct Vector3 {
    Fix12i x;
    Fix12i y;
    Fix12i z;
} Vector3;

typedef struct Camera {
    char _pad0[0x80];
    Vector3 lookAt;     // 0x80 (lookAt.y @ 0x84)
    Vector3 pos;        // 0x8c (pos.y    @ 0x90)
} Camera;

// sub-object living at +0x5c of the 0x13 object; the approach base is at its +4.
typedef struct Sub13 {
    int unk0;           // +0x00
    int base;           // +0x04
} Sub13;

typedef struct Obj13 {
    char _pad0[0x5c];
    Sub13 sub;          // 0x5c
} Obj13;

extern Obj13* func_0200e55c(int id);                                              // 0x0200e55c
extern void Math_Function_0203b0fc(int* val, int target, int step, int maxDelta); // 0x0203b0fc

int func_020080f0(Camera* self) {
    Sub13* s = &func_0200e55c(0x13)->sub;
    Math_Function_0203b0fc(&self->pos.y, s->base + 0x23000, 0x51, 0x7fffffff);
    Math_Function_0203b0fc(&self->lookAt.y, s->base + 0x7d000, 0x266, 0x7fffffff);
    return 1;
}