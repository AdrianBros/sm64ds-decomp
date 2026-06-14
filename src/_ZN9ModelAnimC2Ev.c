extern void _ZN5ModelC2Ev(void* self);
extern void _ZN9AnimationC2Ev(void* self);

extern unsigned int _ZTV9ModelAnim[];
extern unsigned int VTable_Animation_ModelAnimThunk[];

typedef struct {
    unsigned int* vtable;
    char pad_model[0x4c];
    unsigned int* anim_vtable;
    char pad_anim[0xc];
    unsigned int unk60;
} ModelAnim;

ModelAnim* _ZN9ModelAnimC2Ev(ModelAnim* this) {
    _ZN5ModelC2Ev(this);
    _ZN9AnimationC2Ev((char*)this + 0x50);
    this->vtable = _ZTV9ModelAnim;
    this->anim_vtable = VTable_Animation_ModelAnimThunk;
    this->unk60 = 0;
    return this;
}
