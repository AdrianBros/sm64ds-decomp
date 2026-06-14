/* func_0200d63c at 0x0200d63c
 * Checks if playerID == CURR_PLAYER_ID; if so, calls Camera::ChangeState
 * with a pointer to settingBehaviourTable[12] (offset 0x60 from base 0x0209B008).
 */

typedef unsigned char u8;
typedef int s32;

extern u8 CURR_PLAYER_ID;  /* 0x0209f250 */

struct Camera_State {
    void *OnUpdate;
    void *OnPlayerChangeState;
};

extern struct Camera_State settingBehaviourTable[]; /* 0x0209B008 */

struct Camera {
    char pad[0x50];
};

extern s32 _ZN6Camera11ChangeStateEPNS_5StateE(struct Camera *thiz, struct Camera_State *newState);

void func_0200d63c(struct Camera *thiz, u8 playerID)
{
    if (playerID != CURR_PLAYER_ID)
        return;
    _ZN6Camera11ChangeStateEPNS_5StateE(thiz, &settingBehaviourTable[12]);
}
