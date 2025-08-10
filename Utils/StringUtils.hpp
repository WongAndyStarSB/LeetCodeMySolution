#ifndef STRING_UTILS_HPP
#define STRING_UTILS_HPP


#include <string>
#include <sstream>
#include <fstream>

template <typename IteratorT>
std::string arrToStr(IteratorT begin, IteratorT end) {
    if (begin == end) return "[ ]\n";
    std::ostringstream oss;
    oss << "[ ";
    for (IteratorT it = begin; it != end; ++it) {
        oss << *it;
        if (std::next(it) != end) {
            oss << ", ";
        }
    }
    oss << " ]\n";
    return oss.str();
}


std::vector<std::string> getLinesFromFile(const std::string& file_name, const size_t& reserve_size = 10) {
    std::ifstream file(file_name);
    if (!file.is_open()) {
        throw std::system_error(errno, std::system_category(), "Failed to open file: " + file_name);
    }
    std::string line;
    std::vector<std::string> lines;
    lines.reserve(reserve_size);
    while (std::getline(file, line)) {
        lines.emplace_back(line);
    }
    file.close();
    return lines;
}

#endif