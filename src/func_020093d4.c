struct S {
    char pad[0x108];
    int field_0x108;
};

int func_020093d4(struct S *p, int a) {
    return (int)(((long long)a * p->field_0x108 + 0x800) >> 12);
}
