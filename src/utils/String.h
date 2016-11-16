#pragma once

#include <string>
#include <vector>

namespace FlowEngine {

    namespace String
    {
        static std::vector<std::string> split(const std::string &string, const char delimiter)
        {
            int start = 0, end = string.find_first_of(delimiter);
            std::vector<std::string> result = {string.substr(start, end - start)};
            while(end < std::string::npos) {
                start = end + 1;
                end = string.find_first_of(delimiter, start);
                result.emplace_back(string.substr(start, end - start));
            }

            return result;
        }
    }

}