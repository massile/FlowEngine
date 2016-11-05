#pragma once

#include <string>

class File
{
private:
    std::string m_filename;
public:
    File(const std::string& filename);
    std::string getContents() const;
};
