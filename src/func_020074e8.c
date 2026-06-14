extern int ApproachLinear(int *counter, int dest, int step);

struct Obj {
    char pad0[0xb0];
    int field_0xb0;
    char pad1[0xb8 - 0xb4];
    int field_0xb8;
};

int func_020074e8(struct Obj *o) {
    ApproachLinear(&o->field_0xb8, -0x28000, 0x2000);
    o->field_0xb0 = -0x5000;
    return 1;
}
