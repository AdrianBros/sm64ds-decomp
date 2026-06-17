//cpp
struct M48 { int w[12]; };
struct Vector3 { int x,y,z; };
extern "C" {
extern struct M48* _ZN5Actor11UpdateCarryER6PlayerRK7Vector3(void* self, void* player, struct Vector3* pos);
extern struct Vector3 data_ov078_0212711c[];
void func_ov078_02125f8c(char* c){
    void* player = *(void**)(c+0x494);
    int idx = 0;
    if(player == 0) return;
    if(*(int*)((char*)player+8) == 2) idx = 1;
    struct M48* res = _ZN5Actor11UpdateCarryER6PlayerRK7Vector3(c, player, &data_ov078_0212711c[idx]);
    *(struct M48*)(c+0x2e8) = *res;
}
}
