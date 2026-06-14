extern void *_ZTV12CylinderClsn;
extern void *_ZN12CylinderClsnD2Ev(void *self);
extern void _ZN6Memory16operator_delete2EPv(void *ptr);

struct CylinderClsn {
    void *vtable;
};

void *_ZN12CylinderClsnD0Ev(struct CylinderClsn *self)
{
    self->vtable = &_ZTV12CylinderClsn;
    _ZN12CylinderClsnD2Ev(self);
    _ZN6Memory16operator_delete2EPv(self);
    return self;
}
