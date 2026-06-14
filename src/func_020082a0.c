// func_020082a0 @ 0x020082a0 (Camera member, size 0x58)
// If the passed id (arg3) equals the current global frame counter (u16 at
// KS_FRAME_COUNTER / 0x0209b274), reset some camera clipper state via
// func_020094a8 and store two unaligned ints read out of the src pointer into
// fields 0x14c and 0x150. Then run func_02009414 on the camera and return 1.

typedef int Fix12i;

typedef struct Camera {
    char _pad0[0x14c];
    int unk14c;   // 0x14c
    int unk150;   // 0x150
} Camera;

extern unsigned short KS_FRAME_COUNTER;              // 0x0209b274 (u16 read)
extern int func_020094a8(Camera* self);              // 0x020094a8 (clipper reset)
extern int ReadUnalignedInt(const void* p);          // 0x0200e748
extern int func_02009414(Camera* self);              // 0x02009414

int func_020082a0(Camera* self, const char* src, int id) {
    if (id == KS_FRAME_COUNTER) {
        func_020094a8(self);
        self->unk14c = ReadUnalignedInt(src);
        self->unk150 = ReadUnalignedInt(src + 4);
    }
    func_02009414(self);
    return 1;
}