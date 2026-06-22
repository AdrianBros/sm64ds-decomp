extern unsigned int data_0209ee84;
extern unsigned int data_0209ee8c;

unsigned int _ZN8Particle7Texture12AllocPalVramEjb(unsigned int size, int b){
  if (b) {
    unsigned int a = (size + 7) & ~7;
    unsigned int old = data_0209ee84;
    data_0209ee84 = old + a;
    return old;
  } else {
    unsigned int a = (size + 0xf) & ~0xf;
    unsigned int v = data_0209ee8c - a;
    data_0209ee8c = v;
    return v;
  }
}
