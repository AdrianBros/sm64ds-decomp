extern void func_ov004_020adb1c(int self);
extern void func_ov006_020d3ba0(char *c);
void func_ov006_020d52f0(char *c, int arg)
{
    if (arg == 0) {
        int *p;
        if (*(unsigned int *)(c + 0xbc) >= 0x7cf)
            goto final;
        p = (int *)(((int)c + 0xbc) & 0xFFFFFFFFFFFFFFFF);
        *p = *p + 1;
        if (*(unsigned int *)(c + 0xbc) > 0x270e)
            *(unsigned int *)(c + 0xbc) = 0x270e;
    } else {
        *(int *)((c + 0x5000) + 0x3e8) = 0;
        *(int *)(c + 0xbc) = 0;
        if (*(unsigned int *)(c + 0xbc) > 0x270e)
            *(unsigned int *)(c + 0xbc) = 0x270e;
        func_ov004_020adb1c(*(int *)((c + 0x5000) + 0x3e8));
        *(int *)(c + 0xb4) = *(int *)((c + 0x5000) + 0x3e8);
    }
final:
    func_ov006_020d3ba0(c);
}
