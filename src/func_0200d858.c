typedef int Fix12i;

struct Vector3 { Fix12i x, y, z; };

struct Camera {
    char _pad0[0x80];
    struct Vector3 lookAt;  /* @ 0x80 */
    struct Vector3 pos;     /* @ 0x8c */
};

extern void AddVec3(const struct Vector3 *a, const struct Vector3 *b, struct Vector3 *out);

void func_0200d858(struct Camera *self, const struct Vector3 *offset)
{
    AddVec3(&self->lookAt, offset, &self->lookAt);
    AddVec3(&self->pos, offset, &self->pos);
}
