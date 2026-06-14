struct S {
    char pad[0x170];
    void *field_0x170;
};

extern void *someFunc(int arg);

int func_02008008(struct S *p, int v) {
    p->field_0x170 = someFunc(v);
    return 1;
}
