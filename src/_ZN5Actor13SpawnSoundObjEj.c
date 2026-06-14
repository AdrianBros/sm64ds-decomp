typedef unsigned int u32;
typedef signed char s8;
typedef int s32;

typedef struct { s32 x, y, z; } Vector3;
typedef struct { short x, y, z; } Vector3_16;

struct Actor {
    char pad1[0x5c];
    Vector3 pos;
    char pad2[0x64];
    s8 areaID;
};

typedef struct Actor Actor;

extern Actor* _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(u32 actorID, u32 param1, const Vector3* pos, const Vector3_16* rot, s32 areaID, s32 deathTableID);

void _ZN5Actor13SpawnSoundObjEj(Actor* self, u32 soundObjParam) {
    _ZN5Actor5SpawnEjjRK7Vector3PK10Vector3_16ii(
        0x167,
        soundObjParam,
        &self->pos,
        (const Vector3_16*)0,
        (s32)self->areaID,
        -1
    );
}
