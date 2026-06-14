struct S {
    char pad[0x196];
    short field_0x196;
};

extern void sub(struct S *p, int a);

int func_020098b8(struct S *p) {
    sub(p, 0x13);
    p->field_0x196 = 0x1c;
    return 1;
}
