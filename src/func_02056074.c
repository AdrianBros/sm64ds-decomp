/* func_02056074 at 0x02056074 (size 0x60)
 * Copies count words from src to GetBGChar_0x2054de8()-based VRAM region + offset.
 * Uses DMA channel if available, else CPU copy.
 */

extern unsigned int RENDER_DMA_CHANNEL;

extern void *func_02054de8(void);
extern void DMASyncWordTransfer(unsigned int channel, const void *src, void *dst, unsigned int count);
extern void MultiCopy_Int(const void *src, void *dst, unsigned int count);

void func_02056074(const void *src, unsigned int offset, unsigned int count)
{
    void *base = func_02054de8();
    unsigned int channel = RENDER_DMA_CHANNEL;
    if (channel != (unsigned int)-1) {
        DMASyncWordTransfer(channel, src, (char *)base + offset, count);
    } else {
        MultiCopy_Int(src, (char *)base + offset, count);
    }
}
