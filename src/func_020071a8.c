typedef struct { int x, y, z; } Vector3;

struct Camera {
    char pad0[0x8c];
    Vector3 pos;       /* 0x8c */
    Vector3 ownerPos;  /* 0x98 */
    char pad1[0x19a - 0xa4];
    short field_0x19a; /* 0x19a */
};

extern short Vec3_HorzAngle(const Vector3 *v0, const Vector3 *v1);
extern unsigned short AngleDiff(short ang0, short ang1);

void func_020071a8(struct Camera *cam, short ang, int threshold) {
    short horz = Vec3_HorzAngle(&cam->ownerPos, &cam->pos);
    if ((int)AngleDiff(horz, ang) > threshold) {
        cam->field_0x19a = ang;
    }
}
