/* ExitMinigameMenu at 0x0202ad78
 * Exits the minigame menu, either returning to rec room or fading to main menu.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 RETURN_TO_REC_ROOM;  /* 0x0209f298 */
extern u8 LEVEL_ID;            /* 0x0209f2f8 */

extern void LoadLevelNoReturn(u32 actorID, u32 param, u32 arg2, u32 arg3);
extern void _ZN5Scene14StartSceneFadeEjjt(u32 actorID, u32 param, u16 fadeColor);

void ExitMinigameMenu(void)
{
    if (RETURN_TO_REC_ROOM) {
        LoadLevelNoReturn(0x32, 4, 1, 0);
        LEVEL_ID = 6;
        _ZN5Scene14StartSceneFadeEjjt(3, 0, 0x7fff);
    } else {
        _ZN5Scene14StartSceneFadeEjjt(1, 0, 0);
    }
}
