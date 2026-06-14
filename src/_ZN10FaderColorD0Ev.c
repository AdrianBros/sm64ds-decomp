/* FaderColor::~FaderColor (deleting / D0) at 0x02017598
 *   [this+0] = _ZTV10FaderColor (0x0208eb2c)
 *   bl 0x020177c4 = FaderColor::~FaderColor (D2/base)
 *   bl 0x0203cbcc = Memory::operator_delete2(this)
 * returns this.
 */

struct FaderColor {
    void **vtable; /* 0x0 */
};

extern void *_ZTV10FaderColor[];

extern void *FaderColorD2(struct FaderColor *thiz);          /* 0x020177c4 */
extern void _ZN6Memory16operator_delete2EPv(void *ptr);      /* 0x0203cbcc */

struct FaderColor *_ZN10FaderColorD0Ev(struct FaderColor *thiz)
{
    thiz->vtable = (void **)_ZTV10FaderColor;
    FaderColorD2(thiz);
    _ZN6Memory16operator_delete2EPv(thiz);
    return thiz;
}
