extern int someGlobal;

struct S {
    char pad[0x13c];
    void *field_0x13c;
};

int func_0200af0c(struct S *p) {
    p->field_0x13c = &someGlobal;
    return 1;
}
