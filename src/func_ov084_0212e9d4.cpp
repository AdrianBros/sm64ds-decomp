//cpp
extern "C" {
int _ZN5Actor15GivePlayerCoinsER6Playerhj(void *thisp, void *player, unsigned char count, unsigned int z);
int _ZN5Actor24KillAndTrackInDeathTableEv(void *thisp);
int func_ov084_0212e9d4(void *c, void *player) {
    _ZN5Actor15GivePlayerCoinsER6Playerhj(c, player, 1, 0);
    return _ZN5Actor24KillAndTrackInDeathTableEv(c);
}
}
