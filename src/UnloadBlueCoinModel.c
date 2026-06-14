typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef signed int s32;
typedef signed short s16;
typedef signed char s8;

struct SharedFilePtr { u32 data[4]; };

extern void _ZN13SharedFilePtr7ReleaseEv(struct SharedFilePtr *self);

extern struct SharedFilePtr BlueCoinModelFile1;
extern struct SharedFilePtr BlueCoinModelFile2;

void UnloadBlueCoinModel(void)
{
    _ZN13SharedFilePtr7ReleaseEv(&BlueCoinModelFile1);
    _ZN13SharedFilePtr7ReleaseEv(&BlueCoinModelFile2);
}
