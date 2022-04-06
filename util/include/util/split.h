/*
    courtesy of: https://stackoverflow.com/users/13430/evan-teran
    .> https://stackoverflow.com/questions/236129/how-do-i-iterate-over-the-words-of-a-string

    Redistributed under the MIT License,
    PM if there is any issue with that.
*/
#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <iterator>

namespace util {

    template <typename T>
    void split(const std::string& s, char delim, T result) {
        std::istringstream iss(s);
        std::string item;
        while (std::getline(iss, item, delim)) {
            *result++ = item;
        }
    }

    std::vector<std::string> split(const std::string& s, char delim);
}