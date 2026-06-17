extern int func_ov102_02149078(void *c);
extern void _ZN6Player16IncMegaKillCountEv(void *p);
extern void func_ov102_02149da8(void *c, int i);
void func_ov102_02149710(void *c, void *player)
{
    if (*(int*)((char*)c+0x3e8) == 1) return;
    if (func_ov102_02149078(c) != 0) return;
    _ZN6Player16IncMegaKillCountEv(player);
    *(unsigned char*)((char*)c+0x3f2) = *(int*)((char*)player+8);
    func_ov102_02149da8(c, 1);
}
