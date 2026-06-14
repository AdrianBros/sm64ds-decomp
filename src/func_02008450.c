struct S {
    unsigned char pad[0x17a];
    short field_0x17a;
};

extern short someFunc(int x);

int func_02008450(struct S *p, int arg1) {
    p->field_0x17a = someFunc(arg1);
    return 1;
}
