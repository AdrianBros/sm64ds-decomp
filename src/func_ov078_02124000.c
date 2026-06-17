extern int _ZN5Actor18HorzAngleToCPlayerEv(void*);
extern void ApproachAngle(void*,int,int,int,int);
extern int _ZN9Animation8FinishedEv(void*);
extern int func_ov078_02125c48(void*,void*);
extern int data_ov078_0212703c[];
int func_ov078_02124000(char* c){
  int ang = _ZN5Actor18HorzAngleToCPlayerEv(c);
  ApproachAngle((char*)c+0x94, ang, 1, 0x500, 0x500);
  *(short*)(c+0x8e)=*(short*)(c+0x94);
  if(_ZN9Animation8FinishedEv((char*)c+0x31c)){
    func_ov078_02125c48(c, data_ov078_0212703c);
  }
  return 1;
}
