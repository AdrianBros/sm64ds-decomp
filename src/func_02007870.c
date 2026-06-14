// func_02007870 @ 0x02007870 - Camera member, size 0x54.
// Reads three packed unaligned s16 values (a Vector3_16) from a data record
// and forwards them to a Camera helper at 0x0200d8ac, then returns 1.

typedef short s16;
typedef int s32;

extern s16 ReadUnalignedShort(const void *p);       // 0x0200e768
extern void func_0200d8ac(void *self, s16 a, s16 b, s16 c); // 0x0200d8ac

s32 func_02007870(void *self, const unsigned char *data)
{
    s16 a = ReadUnalignedShort(data);
    s16 b = ReadUnalignedShort(data + 2);
    s16 c = ReadUnalignedShort(data + 4);
    func_0200d8ac(self, a, b, c);
    return 1;
}