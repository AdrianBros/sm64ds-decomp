typedef signed char s8;
typedef unsigned char u8;

struct Camera;

extern s8 LEVEL_ID;
extern u8 STAR_OBTAINED_COPY;

extern s8 SublevelToLevel(s8 levelID);
extern void func_020071a8(struct Camera *cam, short ang, int threshold);

int func_020077f0(struct Camera *cam) {
    s8 lvl = SublevelToLevel(LEVEL_ID);
    if (lvl == 2 && STAR_OBTAINED_COPY == 5) {
        func_020071a8(cam, 0, 0x4000);
    } else if (lvl == 8 && STAR_OBTAINED_COPY == 1) {
        func_020071a8(cam, -0x8000, 0x5000);
    }
    return 1;
}
