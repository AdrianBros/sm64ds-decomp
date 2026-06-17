//cpp
extern "C" {
typedef unsigned int u32;
struct SharedFilePtr { u32 data[4]; };
void _ZN13SharedFilePtr7ReleaseEv(struct SharedFilePtr *self);
extern struct SharedFilePtr data_ov019_02113498;
extern struct SharedFilePtr* func_ov032_02112788[7];
extern struct SharedFilePtr* data_ov019_0211277c[3];
int func_ov019_021122f8(void){
  int i;
  _ZN13SharedFilePtr7ReleaseEv(&data_ov019_02113498);
  for(i=0;i<7;i++) _ZN13SharedFilePtr7ReleaseEv(func_ov032_02112788[i]);
  for(i=0;i<3;i++) _ZN13SharedFilePtr7ReleaseEv(data_ov019_0211277c[i]);
  return 1;
}
}
