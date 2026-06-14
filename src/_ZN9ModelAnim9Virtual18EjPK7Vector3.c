typedef unsigned int u32;
typedef int Fix12i;

struct Vector3 { Fix12i x, y, z; };
struct Matrix4x3 { Fix12i r[12]; };

struct ModelBase {
    u32 *vtable;
    u32 unk04;
    virtual ~ModelBase();
    virtual bool DoSetFile(void *file, int a, int b) = 0;
};

struct Model : ModelBase {
    void *data[5];
    Matrix4x3 mat4x3;
    Matrix4x3 *unkMatPtr;
    virtual ~Model();
    virtual bool DoSetFile(void *file, int a, int b);
    virtual void UpdateVerts();
    virtual void Virtual10(Matrix4x3 &arg0);
    virtual void Render(const Vector3 *scale = 0);
    void Render_impl(const Vector3 *scale);
};

struct Animation {
    u32 pad[4];
};

struct ModelAnim : Model, Animation {
    void *file;
    virtual ~ModelAnim();
    virtual void UpdateVerts();
    virtual void Virtual10(Matrix4x3 &arg0);
    virtual void Render(const Vector3 *scale = 0);
    virtual void Virtual18(u32 arg0, const Vector3 *scale);
};

extern void _ZN5Model6RenderEPK7Vector3(ModelAnim *thiz, const Vector3 *scale);

void ModelAnim::Virtual18(u32 arg0, const Vector3 *scale)
{
    Virtual10(*(Matrix4x3*)arg0);
    _ZN5Model6RenderEPK7Vector3(this, scale);
}
