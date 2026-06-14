typedef signed char s8;
typedef int s32;

extern s8 STAR_OBTAINED_COPY;
extern void* unkTable_020876e4[];

extern s32 GetStarCameraSetting(s32 star);
extern void RunKuppaScript(void* script);

void func_0200ee8c(s32 arg0)
{
    s32 idx;
    if (arg0 < 0)
    {
        arg0 = GetStarCameraSetting((s32)STAR_OBTAINED_COPY);
    }
    RunKuppaScript(unkTable_020876e4[arg0]);
}
