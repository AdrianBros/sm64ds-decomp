typedef unsigned char u8;

struct SharedFilePtr {
    unsigned short fileID;
    u8 numRefs;
    char* filePtr;
};

extern void _ZN13SharedFilePtr8LoadFileEv(struct SharedFilePtr* fp);
extern void _ZN9Animation17UpdateFileOffsets_ZN9AnimationER8BCA_File(char* file);

char* _ZN9Animation8LoadFileER13SharedFilePtr(struct SharedFilePtr* filePtr)
{
    u8 refs;
    char* file;

    _ZN13SharedFilePtr8LoadFileEv(filePtr);
    refs = filePtr->numRefs;
    file = filePtr->filePtr;
    if (refs == 1 && file != 0) {
        _ZN9Animation17UpdateFileOffsets_ZN9AnimationER8BCA_File(file);
    }
    return file;
}
