/* func_02007450 @ 0x02007450, size 0x34, ARM.
 * Camera member function: rotates the saved look-at vector (0xb0) by the
 * camera facing angle (0x186 = owner->ang.y + 0x8000) and translates it by
 * the vector at 0x8c, writing the result back into 0x8c. Returns 1.
 */

struct Vector3 { int x, y, z; };

extern void Vec3_RotateYAndTranslate(struct Vector3 *res,
                                     const struct Vector3 *translation,
                                     short angY,
                                     const struct Vector3 *v);

struct Camera {
    char pad0[0x8c];
    struct Vector3 vec8c;    /* 0x8c : Vector3 (pos region) */
    char pad1[0xb0 - 0x98];
    struct Vector3 savedLookAt; /* 0xb0 : savedLookAt (Vector3) */
    char pad2[0x186 - 0xbc];
    short angFacing;         /* 0x186 : owner->ang.y + 0x8000 */
};

int func_02007450(struct Camera *cam) {
    Vec3_RotateYAndTranslate(&cam->vec8c, &cam->vec8c, cam->angFacing,
                             &cam->savedLookAt);
    return 1;
}
