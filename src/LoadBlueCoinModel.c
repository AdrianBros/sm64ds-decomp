typedef struct { int unk[1]; } SharedFilePtr;

extern SharedFilePtr COIN_BLUE_POLY4_MODEL_PTR;   /* 0x0210da00 */
extern SharedFilePtr COIN_BLUE_POLY32_MODEL_PTR;  /* 0x0210d9c8 */

extern void _ZN5Model8LoadFileER13SharedFilePtr(SharedFilePtr* ptr); /* 0x02017a3c */

void LoadBlueCoinModel(void)
{
    _ZN5Model8LoadFileER13SharedFilePtr(&COIN_BLUE_POLY4_MODEL_PTR);
    _ZN5Model8LoadFileER13SharedFilePtr(&COIN_BLUE_POLY32_MODEL_PTR);
}
