#include "Q3.hpp"

#include <vector>
#include <stdexcept>
#include <fstream>
#include <iostream>

#include "../Utils/StringUtils.hpp"


#include "MySolution2.inl"

int main() {
    try {
        Solution solution;
        std::vector<std::string> qs = getLinesFromFile("Q3strings.txt");
        std::vector<int> anss = {};
        anss.reserve(qs.size());
        for (size_t i = 0; i < qs.size(); ++i) {
            anss.emplace_back(solution.lengthOfLongestSubstring(qs[i]));
        }
        std::ostringstream oss;
        for (size_t i = 0; i < qs.size(); ++i) {
            oss << "q: " << qs[i] << " | ans: " << std::to_string(anss[i]) << "\n";
        }
        std::cout << oss.str();

    } catch (std::exception& e) {
        std::cout << "error caught:\n";
        std::cerr << e.what();
        return 1;
    }
    return 0;
}