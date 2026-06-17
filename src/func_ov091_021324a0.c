extern int _ZN16MeshColliderBase9IsEnabledEv(void *);
extern void _ZN16MeshColliderBase7DisableEv(void *);
extern void _ZN13SharedFilePtr7ReleaseEv(void *);
extern char data_ov091_02135024[];
extern char data_ov091_02135028[];
int func_ov091_021324a0(char *t){
  if(_ZN16MeshColliderBase9IsEnabledEv(t+0x124))
    _ZN16MeshColliderBase7DisableEv(t+0x124);
  _ZN13SharedFilePtr7ReleaseEv(*(void**)(data_ov091_02135024 + (unsigned char)t[0x322]*0xc));
  _ZN13SharedFilePtr7ReleaseEv(*(void**)(data_ov091_02135028 + (unsigned char)t[0x322]*0xc));
  return 1;
}
