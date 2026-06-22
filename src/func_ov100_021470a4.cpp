//cpp
struct Obj { virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void m(int); };
extern "C" {
extern void func_ov002_020efc74(void* c);
int func_ov100_021470a4(char* c){
  unsigned short h = *(unsigned short*)(c+0x428);
  if(h < 0x5a){
    if(h & 1) return 1;
  }
  func_ov002_020efc74(c);
  ((Obj*)(c+0xd4))->m(0);
  return 1;
}
}
