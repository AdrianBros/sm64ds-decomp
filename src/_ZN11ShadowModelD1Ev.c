/* ShadowModel::~ShadowModel (D1) at 0x02015ff8
 *
 * Unlinks `this` from a global intrusive doubly-linked list of shadow models,
 * then chains to ModelBase::~ModelBase (D2 @0x020170b8) and returns this.
 *
 * List node fields (relative to this):
 *   +0x20 = prev (ShadowModel*)
 *   +0x24 = next (ShadowModel*)
 * Global list head: 0x0209cef4 (ShadowModel*).
 *
 * Unlink pattern:
 *   if (prev)      prev->next = next;       [r1+0x24] = [this+0x24]
 *   else if (head == this) head = next;
 *   if (next)      next->prev = prev;       [r1+0x20] = [this+0x20]
 *   prev = next = 0;
 */
struct ShadowModel {
    void *vtable;          /* 0x00 */
    char _pad[0x20 - 4];   /* 0x04..0x1f */
    struct ShadowModel *prev; /* 0x20 */
    struct ShadowModel *next; /* 0x24 */
};

extern void *vtbl_ShadowModel[];
extern struct ShadowModel *gShadowModelListHead; /* 0x0209cef4 */
extern void ModelBase_dtor(struct ShadowModel *thiz); /* 0x020170b8 */

struct ShadowModel *_ZN11ShadowModelD1Ev(struct ShadowModel *thiz)
{
    struct ShadowModel *prev;
    struct ShadowModel *next;

    thiz->vtable = (void *)vtbl_ShadowModel;

    prev = thiz->prev;
    if (prev) {
        prev->next = thiz->next;
    } else if (gShadowModelListHead == thiz) {
        gShadowModelListHead = thiz->next;
    }

    next = thiz->next;
    if (next) {
        next->prev = thiz->prev;
    }

    thiz->prev = 0;
    thiz->next = 0;

    ModelBase_dtor(thiz);
    return thiz;
}
