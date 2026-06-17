extern int ApproachLinear(int *r, int a, int b);
extern int ApproachLinear2(short *r, short a, short b);
extern int func_ov004_020b39a4(void *c);
int func_ov004_020b3c58(char *c)
{
    int r;
    ApproachLinear((int*)(c+0x24), *(int*)(c+0x28), 0x1000);
    r = ApproachLinear2((short*)(c+0x12), *(short*)(c+0x16), 0x10);
    if (r == 0)
        return r;
    return func_ov004_020b39a4(c);
}
