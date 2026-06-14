/* _ZN5FaderD0Ev at 0x02017848
 * Single-vtable destructor: write own vtable, call base/helper destructor (0x0203cbcc), return this.
 */
struct Obj { void *vtable; };
extern void *vtbl_Fader[];
extern void base_dtor_Fader(struct Obj *thiz); /* 0x0203cbcc */
struct Obj *_ZN5FaderD0Ev(struct Obj *thiz)
{
    thiz->vtable = (void *)vtbl_Fader;
    base_dtor_Fader(thiz);
    return thiz;
}
