#include "OpenGLTexture.h"

OpenGLTexture::OpenGLTexture(int w, int h, GLenum format)
    : m_TextureID(0)
    , m_Width(w)
    , m_Height(h)
    , m_format(format)
{
}

void OpenGLTexture::Bind()
{
    glBindTexture(GL_TEXTURE_2D,m_TextureID);
}

void OpenGLTexture::resize(int w, int h)
{
    m_Width = w;
    m_Height = h;

    Invalidate();
}

void OpenGLTexture::Invalidate()
{
    if(m_TextureID)
    {
        glDeleteTextures(1, &m_TextureID);
    }
    glCreateTextures(GL_TEXTURE_2D,1,&m_TextureID);
    glBindTexture(GL_TEXTURE_2D, m_TextureID);
    glTextureStorage2D(m_TextureID, 1 , m_format, static_cast<GLsizei>(m_Width), static_cast<GLsizei>(m_Height));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
}

unsigned int OpenGLTexture::RenderID()
{
    return m_TextureID;
}

void OpenGLTexture::Create()
{
    Invalidate();
}

