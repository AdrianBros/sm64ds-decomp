typedef int Fix12i;
typedef unsigned int u32;

struct Actor { void* vtable; };

extern void _ZN12CylinderClsn4InitE5Fix12IiES1_jj(void* self, Fix12i radius, Fix12i height, u32 flags, u32 vulnFlags);

void _ZN18MovingCylinderClsn4InitEP5Actor5Fix12IiES3_jj(
    void* self,
    struct Actor* actor,
    Fix12i radius,
    Fix12i height,
    u32 flags,
    u32 vulnFlags)
{
    *((struct Actor**)((char*)self + 0x30)) = actor;
    _ZN12CylinderClsn4InitE5Fix12IiES1_jj(self, radius, height, flags, vulnFlags);
}