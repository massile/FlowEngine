#pragma once

#include <string>

enum FileFormat
{
    OBJ
};

template <typename T>
class Parser
{
protected:
    std::string m_filepath;
    FileFormat m_fileFormat;

public:
    Parser(const std::string& filepath, FileFormat format) : m_filepath(filepath), m_fileFormat(format) {}
    virtual ~Parser() {}
    virtual T parse() = 0;

    inline FileFormat getFormat() const { return m_fileFormat; }
};
