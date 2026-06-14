extern void *_ZTV4Heap;
extern void _ZN6Memory16operator_delete2EPv(void *ptr);

struct Heap {
    void *vtable;
};

void *_ZN4HeapD0Ev(struct Heap *self)
{
    self->vtable = &_ZTV4Heap;
    _ZN6Memory16operator_delete2EPv(self);
    return self;
}
