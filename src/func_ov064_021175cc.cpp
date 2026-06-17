//cpp
extern "C" {
extern int func_ov064_0211616c(void*);
extern void _ZN5Actor14TriplePoofDustEv(void*);
extern void _ZN5Actor19UntrackAndSpawnStarERajRK7Vector3j(void*,void*,unsigned int,void*,unsigned int);
int func_ov064_021175cc(char* c){
  int r=func_ov064_0211616c(c);
  if(r==0) return r;
  _ZN5Actor14TriplePoofDustEv(c);
  int v[3];
  v[0]=*(int*)(c+0x5c);
  v[1]=*(int*)(c+0x60);
  v[2]=*(int*)(c+0x64);
  v[1]+=0x64000;
  _ZN5Actor19UntrackAndSpawnStarERajRK7Vector3j(
    c, c+0x3fd, (*(unsigned char*)(c+0x3fc)|0x40)&0xff, v, 4);
}
}
