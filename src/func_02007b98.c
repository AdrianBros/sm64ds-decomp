typedef int Fix12i;

struct Vector3 {
    Fix12i x, y, z;
};

struct Actor {
    char pad0[0x5c];
    struct Vector3 pos; /* 0x5c */
};

struct Camera {
    char pad0[0x80];
    char field_0x80[0x10]; /* 0x80 */
    char pad1[0x110 - 0x90];
    struct Actor *owner; /* 0x110 */
};

struct Data {
    short x;        /* 0 */
    short y;        /* 2 */
    short z;        /* 4 */
    unsigned char b6; /* 6 */
};

extern short ReadUnalignedShort(const void *p);
extern void AddVec3(const struct Vector3 *a, const struct Vector3 *b, struct Vector3 *dest);
extern int func_02007cec(void *self, const struct Vector3 *v, int a);

int func_02007b98(struct Camera *cam, struct Data *data) {
    struct Vector3 v;
    Fix12i x, y, z;
    int b;
    z = ReadUnalignedShort(&data->z) << 12;
    y = ReadUnalignedShort(&data->y) << 12;
    x = ReadUnalignedShort(&data->x) << 12;
    v.x = x;
    v.y = y;
    v.z = z;
    b = data->b6 << 4;
    AddVec3(&v, &cam->owner->pos, &v);
    func_02007cec(&cam->field_0x80, &v, b);
    return 1;
}
