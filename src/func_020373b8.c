struct WithMeshClsn { void **vtable; };
extern void *_ZTV12WithMeshClsn[];
extern void _ZN11RaycastLineD1Ev(void *thiz);
extern void _ZN10SphereClsnD1Ev(void *thiz);
extern void WithMeshClsn_BaseDtor(struct WithMeshClsn *thiz);   /* base D2 @0x020354d0 */
extern void _ZN6Memory16operator_delete2EPv(void *ptr);

struct WithMeshClsn *func_020373b8(struct WithMeshClsn *thiz)
{
    thiz->vtable = (void **)_ZTV12WithMeshClsn;
    _ZN11RaycastLineD1Ev((char *)thiz + 0x134);
    _ZN10SphereClsnD1Ev((char *)thiz + 0x20);
    WithMeshClsn_BaseDtor(thiz);
    _ZN6Memory16operator_delete2EPv(thiz);
    return thiz;
}
