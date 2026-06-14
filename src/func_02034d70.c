typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed char s8;
typedef int s32;

extern void _ZN5Scene20SetAndStopColorFaderEv(void);

extern void* SCENE_RELATED;  /* 0x0209d4a8 */

int func_02034d70(void) {
    SCENE_RELATED = 0;
    _ZN5Scene20SetAndStopColorFaderEv();
    return 1;
}
