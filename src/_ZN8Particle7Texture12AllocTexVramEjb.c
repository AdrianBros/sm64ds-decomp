typedef unsigned int u32;

extern u32 _ZN5Model13GetVramOffsetEj(u32 size);

extern u32 unk_0209ee88;

u32 _ZN8Particle7Texture12AllocTexVramEjb(u32 size, int isTexel4x4) {
    if (isTexel4x4) {
        u32 old = unk_0209ee88;
        unk_0209ee88 = old + size;
        return old;
    } else {
        return _ZN5Model13GetVramOffsetEj(size);
    }
}
