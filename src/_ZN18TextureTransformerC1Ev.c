extern void _ZN9AnimationC2Ev(void* self);

extern unsigned int _ZTV18TextureTransformer[];

typedef struct {
    unsigned int* vtable;
    char pad[0xc];
    unsigned int unk10;
} TextureTransformer;

TextureTransformer* _ZN18TextureTransformerC1Ev(TextureTransformer* this) {
    _ZN9AnimationC2Ev(this);
    this->vtable = _ZTV18TextureTransformer;
    this->unk10 = 0;
    return this;
}
