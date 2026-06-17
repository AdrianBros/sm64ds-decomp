//cpp
struct C;
typedef int (C::*PMF)();
struct Entry { char pad[0x8]; PMF pmf; };
struct C { char pad[0x1a4]; Entry *ep; };
extern "C" int func_ov080_02126c60(C *c) {
  (c->*c->ep->pmf)();
  return 1;
}
