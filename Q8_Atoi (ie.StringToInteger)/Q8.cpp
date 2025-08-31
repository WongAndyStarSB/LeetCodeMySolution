#define Q8_CPP

#include <sstream>
#include <iostream>


#include "Q8.hpp"
#include "../Utils/Utils.hpp"

#if Q8_HPP_VALID_SOURCE

int main() {
    try {
        Solution solution;
        std::stringstream ss;
        Question tc[TEST_CASES_LEN];
        std::copy(TEST_CASES, TEST_CASES + TEST_CASES_LEN, tc);
        
        for (size_t i = 0; i < TEST_CASES_LEN; ++i) {
            ss << tc[i].QAtoString(tc[i].solve(solution)) << "\n";
        }
        std::cout << ss.str();
    } catch (std::exception& e) {
        std::cout << "main: ExceptionCaught\n";
        std::cerr << e.what();
    }
}

#endif // Q8_HPP_VALID_SOURCE
#undef THINGS_DEFINED