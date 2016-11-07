#pragma once

#include <string>
#include <GL/glew.h>

namespace FlowEngine { namespace Graphics {

    class Texture
    {
    private:
        std::string m_filename;
        GLuint m_id;
        int m_width;
        int m_height;
    public:
        Texture(const std::string& filename);
        ~Texture();

        void bind() const;
        void unbind() const;

        inline const GLuint getWidth() const { return m_width; }
        inline const GLuint getHeight() const { return m_height; }
        inline const GLuint getId() const { return m_id; }

    private:
        GLuint load();
    };

}}
