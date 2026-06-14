typedef int Fix12i;

struct Matrix3x3 {
    Fix12i v[9]; /* 0x24 bytes */
};

struct Matrix4x3 {
    Fix12i v[9];   /* 0x00 - 0x24 (3x3 rotation) */
    Fix12i tx;     /* 0x24 */
    Fix12i ty;     /* 0x28 */
    Fix12i tz;     /* 0x2c */
};

struct Quaternion {
    Fix12i x, y, z, w;
};

extern void Matrix3x3_FromQuaternion(const struct Quaternion* q, struct Matrix4x3* mF);

void Matrix4x3_FromQuaternion(const struct Quaternion* q, struct Matrix4x3* mF) {
    Matrix3x3_FromQuaternion(q, mF);
    mF->tx = 0;
    mF->ty = 0;
    mF->tz = 0;
}
