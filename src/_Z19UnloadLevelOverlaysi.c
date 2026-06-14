/* _Z19UnloadLevelOverlaysi at 0x0202de64 (72 bytes)
 * UnloadLevelOverlays(s32 levelID) -- unloads per-level overlay then object overlays.
 */

typedef int s32;

extern s32 LOADED_LEVEL_OVL_ID; /* 0x02092130 */

extern void UnloadOverlay(s32 ovID); /* 0x02017f34 */
extern void _Z26LoadOrUnloadObjectOverlaysPFviEi(void (*func)(s32), s32 levelID); /* 0x0202df70 */

void _Z19UnloadLevelOverlaysi(s32 levelID)
{
    if (LOADED_LEVEL_OVL_ID != -1)
    {
        UnloadOverlay(LOADED_LEVEL_OVL_ID);
        LOADED_LEVEL_OVL_ID = -1;
    }
    _Z26LoadOrUnloadObjectOverlaysPFviEi(UnloadOverlay, levelID);
}
