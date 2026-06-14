/* func_0200d5fc at 0x0200d5fc
 * Camera method: if playerID == CURR_PLAYER_ID, call ChangeState then func_0200cb58(thiz, 5).
 */

typedef unsigned char u8;

struct Camera_State;
struct Camera;

extern u8 CURR_PLAYER_ID;  /* 0x0209f250 */
extern struct Camera_State gCameraState_0209b078;  /* 0x0209b078 */
extern void _ZN6Camera11ChangeStateEPNS_5StateE(struct Camera *thiz, struct Camera_State *state); /* 0x0200cb70 */
extern void func_0200cb58(struct Camera *thiz, int index); /* 0x0200cb58 */

void func_0200d5fc(struct Camera *thiz, int playerID)
{
    if (playerID != (int)CURR_PLAYER_ID)
        return;
    _ZN6Camera11ChangeStateEPNS_5StateE(thiz, &gCameraState_0209b078);
    func_0200cb58(thiz, 5);
}
