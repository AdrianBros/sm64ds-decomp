// func_02007d0c @ 0x02007d0c (size 0x4c)
// Approaches a destination Vector3 (self->x/y/z) toward a source Vector3
// (src->x/y/z) using Math_Function_0203b0fc, with a per-axis step
// (stepX/stepY/stepZ) and an unbounded maxDelta (0x7fffffff) on each axis.

typedef int Fix12i;

typedef struct Vector3 {
    Fix12i x;
    Fix12i y;
    Fix12i z;
} Vector3;

// (int* dest, int target, int step, int maxDelta)
extern void Math_Function_0203b0fc(int* val, int target, int step, int maxDelta); // 0x0203b0fc

void func_02007d0c(Vector3* self, Vector3* src, int stepX, int stepY, int stepZ) {
    Math_Function_0203b0fc(&self->x, src->x, stepX, 0x7fffffff);
    Math_Function_0203b0fc(&self->y, src->y, stepY, 0x7fffffff);
    Math_Function_0203b0fc(&self->z, src->z, stepZ, 0x7fffffff);
}