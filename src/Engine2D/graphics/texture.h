#pragma once

#include <string>
#include <GL/glew.h>

namespace FlowEngine { namespace Graphics {

    class Texture
    {
    private:
        std::string mFilename;
        std::string mName;

        GLuint mID;
        int mWidth;
        int mHeight;
    public:
        Texture(const std::string& name, const std::string& filename);
        ~Texture();

        void bind() const;
        void unbind() const;

        inline const GLuint getWidth() const { return mWidth; }
        inline const GLuint getHeight() const { return mHeight; }
        inline const GLuint getId() const { return mID; }
        inline const std::string& getName() const { return mName; }

    private:
        GLuint load();
    };

}}
