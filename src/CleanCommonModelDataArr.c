/* CleanCommonModelDataArr at 0x02016df8
 *
 * Frees every entry of the global commonModelDataArr, then resets the
 * count and a related global to zero.
 *   for (i = 0; i < numCommonModelData; i++) {
 *       if (arr[i].unk8) operator delete(arr[i].unk8);          (0x0203cbc0 -> _ZdlPv)
 *       if (arr[i].unk4) Memory::operator_delete2(arr[i].unk4); (0x0203cbcc)
 *   }
 *   numCommonModelData = 0;
 *   DAT_0209cef0 = 0;
 */

struct CommonModelDataEntry {
    void *unk0;   /* 0x0 */
    void *unk4;   /* 0x4: freed via Memory::operator_delete2 */
    void *unk8;   /* 0x8: freed via operator delete */
};

extern int numCommonModelData;                  /* 0x0209cef8 */
extern struct CommonModelDataEntry commonModelDataArr[]; /* 0x0209cefc (array base) */
extern void *DAT_0209cef0;                       /* 0x0209cef0 */

extern void _ZdlPv(void *ptr);
extern void _ZN6Memory16operator_delete2EPv(void *ptr);

void CleanCommonModelDataArr(void)
{
    struct CommonModelDataEntry *e = &commonModelDataArr[0];
    int i = 0;

    if (numCommonModelData > 0) {
        do {
            if (e->unk8)
                _ZdlPv(e->unk8);
            if (e->unk4)
                _ZN6Memory16operator_delete2EPv(e->unk4);
            i++;
            e++;
        } while (i < numCommonModelData);
    }

    numCommonModelData = 0;
    DAT_0209cef0 = 0;
}
