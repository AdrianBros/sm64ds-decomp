//cpp
struct C;
typedef int (C::*PMF)();
struct Entry { char pad[0x10]; PMF pmf; };
struct C { char pad[0x1a4]; Entry *ep; };
extern "C" int func_ov080_02126c20(C *c) {
  (c->*c->ep->pmf)();
  return 1;
}
