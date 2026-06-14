/* func_02008474 @ 0x02008474, size 0x3c, ARM.
 * Camera-cluster helper: forwards (this, vec, a, b) to one routine, then
 * (this, vec+6, a, b) to another and returns the second call's result.
 * vec points at a pair of adjacent Vector3_16 (s16 x,y,z), the second at +6.
 */

typedef struct { short x, y, z; } Vector3_16;

struct Camera;

extern void func_02008500(struct Camera *self, Vector3_16 *v, int a, int b);
extern int  func_020084b0(struct Camera *self, Vector3_16 *v, int a, int b);

int func_02008474(struct Camera *self, Vector3_16 *v, int a, int b)
{
    func_02008500(self, v, a, b);
    return func_020084b0(self, v + 1, a, b);
}