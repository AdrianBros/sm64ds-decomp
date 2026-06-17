extern int _ZN5Actor22IsTooFarAwayFromPlayerE5Fix12IiE(void *c, int d);
extern void func_ov096_021368b4(void *c);
extern void _ZN5Actor19MakeVanishLuigiWorkER12CylinderClsn(void *c, void *cyl);
extern void func_ov096_02135efc(void *c);
int func_ov096_02136a50(char *c)
{
    int s = *(int *)(c + 0x38c);
    if (s != 2 && s != 5) {
        if (_ZN5Actor22IsTooFarAwayFromPlayerE5Fix12IiE(c, 0x5dc000)) return 1;
    }
    func_ov096_021368b4(c);
    _ZN5Actor19MakeVanishLuigiWorkER12CylinderClsn(c, c + 0x14c);
    func_ov096_02135efc(c);
    return 1;
}
