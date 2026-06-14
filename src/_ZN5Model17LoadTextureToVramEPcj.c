typedef unsigned int u32;

extern u32 _ZN5Model13GetVramOffsetEj(u32 size);
extern void _ZN2GX12BeginLoadTexEv(void);
extern void _ZN2GX7LoadTexEPKvjj(const void* texData, u32 vramOffset, u32 size);
extern void _ZN2GX10EndLoadTexEv(void);

extern u32 VRAM_Tex_Size;

u32 _ZN5Model17LoadTextureToVramEPcj(char* texData, u32 size) {
    u32 vramOffset = _ZN5Model13GetVramOffsetEj(size);
    _ZN2GX12BeginLoadTexEv();
    _ZN2GX7LoadTexEPKvjj((const void*)texData, vramOffset, size);
    VRAM_Tex_Size += size;
    _ZN2GX10EndLoadTexEv();
    return vramOffset;
}
