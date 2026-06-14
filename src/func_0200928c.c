typedef int Fix12i;

struct Vector3 {
    Fix12i x, y, z;
};

struct Camera {
    char _pad00[0x80];
    struct Vector3 lookAt;  /* 0x80 */
    struct Vector3 pos;     /* 0x8c */
    char _pad98[0x17c - 0x98];
    short fov;              /* 0x17c */
    short unk17e;           /* 0x17e */
};

extern short Vec3_HorzAngle(const struct Vector3 *v0, const struct Vector3 *v1);
extern short Vec3_VertAngle(const struct Vector3 *v1, const struct Vector3 *v0);

void func_0200928c(struct Camera *cam)
{
    cam->fov = Vec3_HorzAngle(&cam->lookAt, &cam->pos);
    cam->unk17e = Vec3_VertAngle(&cam->lookAt, &cam->pos);
}