extern char *_ZN5Actor10FindWithIDEj(unsigned int id);
extern void func_ov064_02118c48(void *c);
void func_ov064_02118d3c(char *c){
  if (*(unsigned char*)(c+0x33a) != 0) {
    unsigned int id = *(unsigned int*)(c+0x320);
    if (id != 0) {
      char *a = _ZN5Actor10FindWithIDEj(id);
      if (a != 0 && *(unsigned char*)(a+0xd5) == 1) {
        *(char*)(c+0x33a) = 0;
        func_ov064_02118c48(c);
      }
    }
  }
  if (*(unsigned short*)(c+0x334) >= 0x18)
    *(char*)(c+0x339) = 0;
}
