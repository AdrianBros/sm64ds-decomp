typedef int s32;

extern void* INTRO_CUTSCENE;

extern void _ZN5Sound16LoadInitialGroupEi(s32 group);
extern void RunKuppaScript(void* script);

void StartIntroCutscene(void)
{
    _ZN5Sound16LoadInitialGroupEi(0x25);
    RunKuppaScript(&INTRO_CUTSCENE);
}
