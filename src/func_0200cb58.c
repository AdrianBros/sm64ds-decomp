struct Element {
    char data[0x28];
};

struct Obj {
    char pad[0x13c];
    struct Element *ptr;
};

extern struct Element someArray[];

void func_0200cb58(struct Obj *obj, int index) {
    obj->ptr = &someArray[index];
}
