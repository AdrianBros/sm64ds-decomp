typedef signed char s8;

extern s8 AREA_ID;

extern void HideArea(void);
extern void ShowArea(int areaID);

void ChangeArea(int areaID)
{
    if (AREA_ID >= 0)
        HideArea();
    AREA_ID = (s8)areaID;
    ShowArea(areaID);
}
