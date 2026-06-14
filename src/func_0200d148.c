/* func_0200d148 at 0x0200d148
 * Camera method: if playerID == CURR_PLAYER_ID, call ChangeState with settingBehaviourTable[34].
 */

typedef unsigned char u8;
typedef int s32;

extern u8 CURR_PLAYER_ID;  /* 0x0209f250 */

struct Camera_State {
    void *OnUpdate;
    void *OnPlayerChangeState;
};

extern struct Camera_State settingBehaviourTable[];  /* 0x0209B008 */

struct Camera {
    char pad[0x50];
};

extern s32 _ZN6Camera11ChangeStateEPNS_5StateE(struct Camera *thiz, struct Camera_State *newState);

void func_0200d148(struct Camera *thiz, u8 playerID)
{
    if (playerID != CURR_PLAYER_ID)
        return;
    _ZN6Camera11ChangeStateEPNS_5StateE(thiz, &settingBehaviourTable[34]);
}
