//cpp
struct Sub {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void doit(int);
};
extern "C" {
int func_ov091_02131408(char *c) {
    if (*(unsigned char*)(c+0x3a0)) return 1;
    if (*(int*)(c+8) == 0xffff) return 1;
    ((struct Sub*)(c+0xd4))->doit(0);
    return 1;
}
}
