typedef short s16;

struct Camera {
    char pad0[0x17a];
    s16 fov;
};

extern s16 ReadUnalignedShort(const char *from);
extern int ApproachLinear2(s16 *counter, s16 dest, s16 step);

int func_0200840c(struct Camera *cam, const char *data) {
    s16 dest = ReadUnalignedShort(data);
    s16 step = ReadUnalignedShort(data + 2);
    ApproachLinear2(&cam->fov, dest, step);
    return 1;
}
