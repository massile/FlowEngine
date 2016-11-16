#pragma once

#include <string>
#include <fstream>
#include <cstring>

namespace FlowEngine {

    namespace FileParser
    {
        static std::string readFile(const std::string& fileName)
        {
            std::string result;
            std::ifstream file(fileName, std::ios::in);
            file.seekg(0, file.end);
            result.resize(file.tellg());
            file.seekg(0, file.beg);
            file.read(&result[0], result.size());

            return result;
        }
    }
}