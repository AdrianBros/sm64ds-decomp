/* func_0200d3f8 at 0x0200d3f8
 * Camera method: if playerID == CURR_PLAYER_ID, store arg2 to this->unk11c,
 * then call ChangeState with settingBehaviourTable[26].
 */

typedef unsigned char u8;
typedef int s32;

extern u8 CURR_PLAYER_ID;  /* 0x0209f250 */

struct Camera_State {
    void *OnUpdate;
    void *OnPlayerChangeState;
};

extern struct Camera_State settingBehaviourTable[];  /* 0x0209B008 */

struct Vector3 { s32 x, y, z; };

struct Camera {
    char pad[0x11c];
    struct Vector3 *unk11c;  /* 0x11c */
};

extern s32 _ZN6Camera11ChangeStateEPNS_5StateE(struct Camera *thiz, struct Camera_State *newState);

void func_0200d3f8(struct Camera *thiz, u8 playerID, struct Vector3 *ptr)
{
    if (playerID != CURR_PLAYER_ID)
        return;
    thiz->unk11c = ptr;
    _ZN6Camera11ChangeStateEPNS_5StateE(thiz, &settingBehaviourTable[26]);
}
