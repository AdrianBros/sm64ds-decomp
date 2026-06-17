extern int func_ov102_02149078(void *c);
extern void func_ov102_02149da8(void *c, int i);
typedef unsigned char u8;
typedef short s16;
void func_ov102_021496a4(void *c, void *x) {
    if (*(int *)((char *)c + 0x3e8) == 1) return;
    *(int *)((char *)c + 0x9c) = -0x8000;
    *(int *)((char *)c + 0xa8) = 0x1e000;
    if (func_ov102_02149078(c)) return;
    *(u8 *)((char *)c + 0x3f2) = *(int *)((char *)x + 8);
    func_ov102_02149da8(c, 1);
}
