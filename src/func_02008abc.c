/* func_02008abc @ 0x02008abc, size 0x4c, ARM.
 * Camera member function: Fix12i-multiplies a per-mode constant from a
 * global s16 table (indexed by a global current-mode byte, stride 0x18)
 * by the camera's s16 field at 0x19c, returning the product as an s16.
 */

typedef int Fix12i; /* 20.12 fixed point */

/* Per-mode camera setting entry; 0x18-byte stride, first field is the s16 read. */
struct CameraModeEntry {
    short field_0x0;
    char pad[0x16];
};

extern unsigned char CAMERA_MODE;             /* 0x020a0e40 : current camera mode (u8) */
extern struct CameraModeEntry CAMERA_MODE_TABLE[]; /* 0x0209f4a2 : table, stride 0x18 */

struct Camera {
    char pad0[0x19c];
    short field_0x19c; /* 0x19c : s16 multiplier */
};

short func_02008abc(struct Camera *cam) {
    Fix12i a = CAMERA_MODE_TABLE[CAMERA_MODE].field_0x0;
    Fix12i b = cam->field_0x19c;
    return (short)(((long long)a * b + 0x800) >> 12);
}
