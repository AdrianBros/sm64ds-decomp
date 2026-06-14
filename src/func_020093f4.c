struct S {
    char pad[0x104];
    int field_0x104;
};

int func_020093f4(struct S *p, int x) {
    return (int)(((long long)x * p->field_0x104 + 0x800) >> 12);
}
