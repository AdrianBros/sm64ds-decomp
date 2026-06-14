extern volatile unsigned char* _ZN2G212GetBG0ScrPtrEv(void);
extern void DMASyncHalfTransfer(int channel, const void* src, volatile void* dst, int count);
extern void MultiCopyHalf(const void* src, volatile void* dst, int count);

extern int RENDER_DMA_CHANNEL;

void func_02056554(const void* src, int offset, int count)
{
    volatile unsigned char* ptr = _ZN2G212GetBG0ScrPtrEv();
    int ch = RENDER_DMA_CHANNEL;
    if (ch != -1)
    {
        DMASyncHalfTransfer(ch, src, ptr + offset, count);
    }
    else
    {
        MultiCopyHalf(src, ptr + offset, count);
    }
}
