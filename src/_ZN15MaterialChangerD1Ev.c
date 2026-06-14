/* _ZN15MaterialChangerD1Ev at 0x0201582c
 * Single-vtable destructor (CodeWarrior 1.2):
 *   write own vtable to [this], call base/helper destructor, return this.
 * Call target: 0x02015cb4
 */
struct Obj { void *vtable; };
extern void *vtbl_MaterialChanger[];
extern void base_dtor_MaterialChanger(struct Obj *thiz); /* 0x02015cb4 */
struct Obj *_ZN15MaterialChangerD1Ev(struct Obj *thiz)
{
    thiz->vtable = (void *)vtbl_MaterialChanger;
    base_dtor_MaterialChanger(thiz);
    return thiz;
}
