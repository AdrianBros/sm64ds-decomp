// func_0200987c @ 0x0200987c (size 0x3c) - Camera member.
// Decrements the u16 timer at 0x196 if it is above 0; when it reaches 0,
// re-points the camera's state pointer via func_0200cb58(self, 0x14). Then
// always calls func_02009e70(self).

typedef unsigned short u16;

typedef struct Camera {
    char _pad0[0x196];
    u16 field_0x196;    // 0x196
} Camera;

extern u16 DecIfAbove0_Short(u16* counter);    // 0x0203adbc
extern void func_0200cb58(Camera* self, int index); // 0x0200cb58
extern void func_02009e70(Camera* self);       // 0x02009e70

void func_0200987c(Camera* self) {
    if (DecIfAbove0_Short(&self->field_0x196) == 0) {
        func_0200cb58(self, 0x14);
    }
    func_02009e70(self);
}
