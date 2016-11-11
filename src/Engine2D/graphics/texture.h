#pragma once

#include <string>
#include <GL/glew.h>

namespace FlowEngine { namespace Graphics {

    class Texture
    {
    private:
        std::string mFilename;
        GLuint mID;
        int mWidth;
        int mHeight;
    public:
        Texture(const std::string& filename);
        ~Texture();

        void bind() const;
        void unbind() const;

        inline const GLuint getWidth() const { return mWidth; }
        inline const GLuint getHeight() const { return mHeight; }
        inline const GLuint getId() const { return mID; }

    private:
        GLuint load();
    };

}}
