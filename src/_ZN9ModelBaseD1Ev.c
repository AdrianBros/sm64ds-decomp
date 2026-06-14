/* _ZN9ModelBaseD1Ev at 0x02017120
 * ModelBase destructor: write own vtable; if member at +4 is non-null,
 * call cleanup(member) (0x02018144); return this.
 */
struct ModelBase {
    void *vtable; /* 0x00 */
    void *res;    /* 0x04 */
};
extern void *vtbl_ModelBase[];
extern void ModelBase_FreeRes(void *res); /* 0x02018144 */
struct ModelBase *_ZN9ModelBaseD1Ev(struct ModelBase *thiz)
{
    thiz->vtable = (void *)vtbl_ModelBase;
    if (thiz->res != 0) {
        ModelBase_FreeRes(thiz->res);
    }
    return thiz;
}
