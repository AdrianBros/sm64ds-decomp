//cpp
struct C;
typedef void (C::*PMF)();
struct C { char pad[0x64]; PMF pp[1]; };
extern "C" {
extern void func_0203083c(void);
int func_ov075_0211a26c(C *c){
  if(*(int*)&c->pp[0]!=0){
    PMF *p = c->pp;
    (c->**p)();
  }
  func_0203083c();
  return 1;
}
}
