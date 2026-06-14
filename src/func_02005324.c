extern void func_a(void *p);
extern void func_b(void *p, int n);

int func_02005324(void *p)
{
    func_a(p);
    func_b(p, 0x19);
    return 1;
}
