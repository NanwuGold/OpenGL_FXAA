#ifndef OPENGL_FXAA_OPENGLTEXTURE_H
#define OPENGL_FXAA_OPENGLTEXTURE_H

#include "Render/Texture.h"

class OpenGLTexture : public Texture
{
public:
    OpenGLTexture(int w, int h, GLenum format);

    void Bind() override;

    void resize(int w, int h) override;

    void Invalidate() override;

    unsigned int RenderID() override;

    void Create() override;

private:
    unsigned int m_TextureID;
    unsigned int m_Width;
    unsigned int m_Height;
    GLenum m_format;
};


#endif //OPENGL_FXAA_OPENGLTEXTURE_H