/* _ZN19CylinderClsnWithPosD1Ev at 0x02014854
 * Single-vtable D1/D2 destructor (CodeWarrior 1.2):
 *   write own vtable to [this], call immediate-base destructor, return this.
 * Base dtor call target: 0x02015058
 */
struct Obj { void *vtable; };
extern void *vtbl_CylinderClsnWithPos[];
extern void base_dtor_CylinderClsnWithPos(struct Obj *thiz); /* 0x02015058 */
struct Obj *_ZN19CylinderClsnWithPosD1Ev(struct Obj *thiz)
{
    thiz->vtable = (void *)vtbl_CylinderClsnWithPos;
    base_dtor_CylinderClsnWithPos(thiz);
    return thiz;
}
