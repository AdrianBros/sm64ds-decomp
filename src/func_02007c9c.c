/* func_02007c9c @ 0x02007c9c, size 0x50, ARM.
 * Given two world points v0 and v1, computes the distance, the vertical
 * angle, and the horizontal angle between them, writing each into its own
 * output pointer. Thin dispatcher over Vec3_Dist / Vec3_VertAngle /
 * Vec3_HorzAngle.
 */

typedef struct { int x, y, z; } Vector3;

extern int   Vec3_Dist(const Vector3 *v0, const Vector3 *v1);
extern short Vec3_VertAngle(const Vector3 *v1, const Vector3 *v0);
extern short Vec3_HorzAngle(const Vector3 *v0, const Vector3 *v1);

void func_02007c9c(const Vector3 *v0, const Vector3 *v1,
                   int *outDist, short *outVertAng, short *outHorzAng) {
    *outDist = Vec3_Dist(v0, v1);
    *outVertAng = Vec3_VertAngle(v1, v0);
    *outHorzAng = Vec3_HorzAngle(v0, v1);
}
