struct ShadowModel {
    void **vtable;       /* 0x0  */
    char pad[0x1c];
    struct ShadowModel *prev;   /* 0x20 */
    struct ShadowModel *next;   /* 0x24 */
};
extern void *_ZTV11ShadowModel[];
extern struct ShadowModel *SHADOW_MODEL_LIST_HEAD;   /* 0x0209cef4 */
extern void _ZN9ModelBaseD2Ev(struct ShadowModel *thiz);
extern void _ZN6Memory16operator_delete2EPv(void *ptr);

struct ShadowModel *_ZN11ShadowModelD0Ev(struct ShadowModel *thiz)
{
    thiz->vtable = (void **)_ZTV11ShadowModel;

    if (thiz->prev)
        thiz->prev->next = thiz->next;
    else if (SHADOW_MODEL_LIST_HEAD == thiz)
        SHADOW_MODEL_LIST_HEAD = thiz->next;

    if (thiz->next)
        thiz->next->prev = thiz->prev;

    thiz->prev = 0;
    thiz->next = 0;

    _ZN9ModelBaseD2Ev(thiz);
    _ZN6Memory16operator_delete2EPv(thiz);
    return thiz;
}
