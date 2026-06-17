extern void _ZN5Sound9PlayBank3EjRK7Vector3(unsigned int id, void* pos);
extern void GiveCoins(int who, int count);
extern void _ZN6Player4HealEi(void* player, int amount);
extern void func_ov102_0214baa0(void* thing);
void func_ov102_0214adc8(void* thing, void* player)
{
    unsigned char flag = *(unsigned char*)((char*)thing + 0x108);
    if (flag == 1) {
        _ZN5Sound9PlayBank3EjRK7Vector3(0x11, (char*)thing + 0x74);
        GiveCoins(*(unsigned char*)((char*)player + 0x6d8), 1);
        _ZN6Player4HealEi(player, 0x100);
    }
    func_ov102_0214baa0(thing);
}
