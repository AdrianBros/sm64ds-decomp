/* _ZN10ModelAnim24CopyERKS_Pcj at 0x02016254
 * ModelAnim2::Copy(const ModelAnim2& src, char* newFile, u32 newUnk64):
 *   copy ModelAnim base (r0=this, r1=src, r2=newFile passed through),
 *   then copy the otherAnim Animation subobject at +0x68 from src's +0x50,
 *   then set unk64 at +0x64 from newUnk64 (if nonzero) or from src->unk64.
 */
extern void _ZN9ModelAnim4CopyERKS_Pc(void *thiz, const void *src, void *newFile);
extern void _ZN9Animation4CopyERKS_(void *thiz, const void *src);

void _ZN10ModelAnim24CopyERKS_Pcj(void *thiz, const void *src, void *newFile, unsigned int newUnk64)
{
    _ZN9ModelAnim4CopyERKS_Pc(thiz, src, newFile);
    _ZN9Animation4CopyERKS_((char *)thiz + 0x68, (const char *)src + 0x50);
    if (newUnk64)
        *(unsigned int *)((char *)thiz + 0x64) = newUnk64;
    else
        *(unsigned int *)((char *)thiz + 0x64) = *(const unsigned int *)((const char *)src + 0x64);
}
