struct Vector3 { int x,y,z; };
extern void _ZN5Actor10EarthquakeERK7Vector35Fix12IiE(void* self, struct Vector3* v, int f);
extern void func_02012694(int a, void* p);
extern void func_ov092_02131578(char* c);
void func_ov092_021315ac(char *c){
  *(int*)(c+0x98)=0;
  if(!*(unsigned short*)(c+0x500+0x64)){
    struct Vector3 v;
    v.x=*(int*)(c+0x5c); v.y=*(int*)(c+0x60); v.z=*(int*)(c+0x64);
    _ZN5Actor10EarthquakeERK7Vector35Fix12IiE(c, &v, 0x860000);
    func_02012694(0x46, c+0x74);
  }
  *(int*)(c+0x60) = *(int*)(c+0x55c) + 0x3000;
  func_ov092_02131578(c);
}
