// func_02008a70 @ 0x02008a70 (Camera member, size 0x4c)
// Reads a current-mode/index byte from a global (gCameraMode), uses it to index
// a global 24-byte-stride table (gCameraModeTable[mode].field_0x0, an s16), and
// Fix12-multiplies that table value by the camera's s16 field at 0x19c, returning
// the rounded result truncated back to s16.

typedef int Fix12i;   // 20.12 fixed point
typedef short Fix12s; // 4.12 fixed point (s16)

struct CameraModeEntry {
    Fix12s field_0x0;   // 0x0 : s16 multiplier for this mode
    char pad[0x18 - 0x2];
};

struct CameraSub {            // sub-object embedded at Camera+0x100
    char pad[0x9c];
    Fix12s field_0x9c;        // 0x9c : s16 operand (Camera+0x19c)
};

struct Camera {
    char pad0[0x100];
    struct CameraSub sub;     // 0x100
};

extern unsigned char gCameraMode;                       // 0x020a0e40
extern struct CameraModeEntry gCameraModeTable[];       // 0x0209f4a4

short func_02008a70(struct Camera *self) {
    Fix12s m = gCameraModeTable[gCameraMode].field_0x0;
    return (short)(((long long)m * self->sub.field_0x9c + 0x800) >> 12);
}