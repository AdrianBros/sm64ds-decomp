typedef int s32;

typedef struct { s32 x, y, z; } Vector3;
typedef struct { s32 m[12]; } Matrix4x3;

/* MovingMeshCollider fields:
 *   0x54 = newTransform  (Matrix4x3)
 *   0xe4 = invMat4x3_0e4 (Matrix4x3)
 */
struct MovingMeshCollider {
    char pad[0x54];
    Matrix4x3 newTransform;    /* 0x54 */
    char pad2[0x60];           /* 0x84 to 0xe3 */
    Matrix4x3 invMat4x3_0e4;  /* 0xe4 */
};

extern void MulVec3Mat4x3(const Vector3* v, const Matrix4x3* m, Vector3* res); /* 0x02052858 */

int _ZN18MovingMeshCollider12TransformPosERK7Vector3RS0_(struct MovingMeshCollider* thiz, const Vector3* pos, Vector3* res)
{
    Vector3 tmp;
    MulVec3Mat4x3(pos, &thiz->invMat4x3_0e4, &tmp);
    MulVec3Mat4x3(&tmp, &thiz->newTransform, res);
    return 1;
}
