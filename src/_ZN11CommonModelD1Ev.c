/* CommonModel::~CommonModel (D1) at 0x020161e0
 * Single-vtable destructor: write own vtable, call ModelBase::~ModelBase (D2 @0x020170b8), return this.
 */
struct Obj { void *vtable; };
extern void *vtbl_CommonModel[];
extern void ModelBase_dtor(struct Obj *thiz); /* 0x020170b8 */
struct Obj *_ZN11CommonModelD1Ev(struct Obj *thiz)
{
    thiz->vtable = (void *)vtbl_CommonModel;
    ModelBase_dtor(thiz);
    return thiz;
}
