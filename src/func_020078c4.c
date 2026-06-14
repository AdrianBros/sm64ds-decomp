// func_020078c4 @ 0x020078c4 - Camera member, size 0x4c.
// Eases the camera's fov (field 0x17a, s16) toward a target angle read
// (unaligned) from a data record, using ApproachAngle with maxDelta 0x4000.
// Returns 1.

typedef short s16;
typedef int s32;

struct Camera {
    unsigned char pad[0x17a];
    s16 fov;            // 0x17a
};

extern s16 ReadUnalignedShort(const void *from);                                   // 0x0200e768
extern s16 ApproachAngle(s16 *angle, s32 targetAngle, s32 invFactor,
                         s32 maxDelta, s32 minDelta);                               // 0x0203b008

s32 func_020078c4(struct Camera *self, const unsigned char *data)
{
    ApproachAngle(&self->fov, ReadUnalignedShort(data), data[2], 0x4000, 0);
    return 1;
}