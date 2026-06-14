extern void *_ZTV4View;
extern void *_ZTV12ActorDerived;
extern void *_ZN9ActorBaseD1Ev(void *self);

struct View {
    void *vtable;
};

void *_ZN4ViewD1Ev(struct View *self)
{
    self->vtable = &_ZTV4View;
    self->vtable = &_ZTV12ActorDerived;
    _ZN9ActorBaseD1Ev(self);
    return self;
}
