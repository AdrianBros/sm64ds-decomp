/* func_02017254 at 0x02017254
 * Single-vtable destructor: write own vtable, call base/helper destructor (0x02017574), return this.
 */
struct Obj { void *vtable; };
extern void *vtbl_func_02017254_obj[];
extern void base_dtor_func_02017254_obj(struct Obj *thiz); /* 0x02017574 */
struct Obj *func_02017254(struct Obj *thiz)
{
    thiz->vtable = (void *)vtbl_func_02017254_obj;
    base_dtor_func_02017254_obj(thiz);
    return thiz;
}
