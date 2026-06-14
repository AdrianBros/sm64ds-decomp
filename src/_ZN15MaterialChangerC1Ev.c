extern void _ZN9AnimationC2Ev(void* self);

extern unsigned int _ZTV15MaterialChanger[];

typedef struct {
    unsigned int* vtable;
    char pad[0xc];
    unsigned int unk10;
} MaterialChanger;

MaterialChanger* _ZN15MaterialChangerC1Ev(MaterialChanger* this) {
    _ZN9AnimationC2Ev(this);
    this->vtable = _ZTV15MaterialChanger;
    this->unk10 = 0;
    return this;
}
