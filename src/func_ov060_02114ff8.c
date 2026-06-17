extern int func_ov060_02115a30(void *);

void func_ov060_02114ff8(void *c) {
    int r = func_ov060_02115a30(c);
    if (r) {
        *(int*)((char*)c + 0x40c) = 0;
    }
}
