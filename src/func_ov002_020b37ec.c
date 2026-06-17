void func_ov002_020b37ec(void *c) {
    unsigned short v = *(unsigned short*)((char*)c + 0xc);
    int b = (int)(v == 0x11);
    if (b) return;
    void (*fn)(void*) = (void(*)(void*))*(int*)((*(int*)c) + 0x7c);
    fn(c);
}
