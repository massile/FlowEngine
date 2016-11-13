#pragma once

#include <string>
#include <GL/glew.h>

namespace FlowEngine { namespace Graphics {

    enum TextureWrap
    {
        REPEAT = GL_REPEAT,
        CLAMP = GL_CLAMP,
        CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
        CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER,
    };

    class Texture
    {
    private:
        static TextureWrap sWrapMode;
    private:
        std::string mFilename = "";
        std::string mName;

        GLuint mID;
        int mWidth;
        int mHeight;
    public:
        Texture(const std::string& name, const std::string& filename);
        Texture(int width, int height);
        ~Texture();

        void bind() const;
        void unbind() const;

        inline const GLuint getWidth() const { return mWidth; }
        inline const GLuint getHeight() const { return mHeight; }
        inline const GLuint getId() const { return mID; }
        inline const std::string& getName() const { return mName; }

    public:
        static void setWrapMode(TextureWrap wrap) { sWrapMode = wrap; }

    private:
        GLuint load();
    };

}}
