typedef int s32;

struct ActorBase {
    char _pad[0x50];
};

struct Actor {
    struct ActorBase base;
    char _pad2[0x70];
};

extern s32 _ZN9ActorBase22BeforeCleanupResourcesEv(struct ActorBase *self);

s32 _ZN5Actor22BeforeCleanupResourcesEv(struct Actor *self)
{
    s32 res = _ZN9ActorBase22BeforeCleanupResourcesEv((struct ActorBase*)self);
    if (res != 0)
        return 1;
    return 0;
}
