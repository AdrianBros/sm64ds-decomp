struct Inner {
    char pad[0x8e];
    short field_0x8e;
};

struct Obj {
    char pad0[0xb0];
    int field_0xb0;
    int field_0xb4;
    int field_0xb8;
    char pad1[0x110 - 0xbc];
    struct Inner *field_0x110;
    char pad2[0x186 - 0x114];
    short field_0x186;
};

int func_0200751c(struct Obj *o) {
    o->field_0x186 = (short)(o->field_0x110->field_0x8e + 0x8000);
    o->field_0xb0 = 0;
    o->field_0xb4 = 0;
    o->field_0xb8 = 0;
    return 1;
}