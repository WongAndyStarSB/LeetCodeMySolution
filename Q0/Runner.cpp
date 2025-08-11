#define GENERAL_RUNNER_CPP

#include <sstream>
#include <iostream>

#include "QuestionHeader.hpp"
#include "Solution.hpp"
#include "../Utils/Utils.hpp"

#if THINGS_DEFINED

int main() {
    try {
        Solution solution;
        std::stringstream ss;
        Question tc[TEST_CASES_LEN];
        std::copy(TEST_CASES, TEST_CASES + TEST_CASES_LEN, tc);

        // std::cout << StringUtils::arrToStr(tc, (tc+TEST_CASES_LEN), Question::staticToString);
        
        for (size_t i = 0; i < TEST_CASES_LEN; ++i) {
            ss << tc[i].QAtoString(tc[i].solve(solution)) << "\n";
        }
        std::cout << ss.str();
    } catch (std::exception& e) {
        std::cout << "main: ExceptionCaught\n";
        std::cerr << e.what();
    }
}

#else

int main() { 
    return 0; 
}

#endif // THINGS_DEFINED
#undef THINGS_DEFINED