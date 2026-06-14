typedef struct Actor { char pad[0]; } Actor;

extern void _ZN5Actor17TrackInDeathTableEv(Actor* self);
extern void _ZN9ActorBase18MarkForDestructionEv(Actor* self);

void _ZN5Actor24KillAndTrackInDeathTableEv(Actor* self) {
    _ZN5Actor17TrackInDeathTableEv(self);
    _ZN9ActorBase18MarkForDestructionEv(self);
}
