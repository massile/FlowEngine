#include "File.h"
#include <fstream>

File::File(const std::string &filename)
    : m_filename(filename)
{

}

std::string File::getContents() const
{
    std::string contents;
    std::ifstream file(m_filename, std::ios::in);
    file.seekg(0, file.end);
    contents.resize(file.tellg());
    file.seekg(0, file.beg);
    file.read(&contents[0], contents.size());

    return contents;
}