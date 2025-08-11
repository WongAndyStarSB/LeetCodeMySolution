#include <sstream>
#include <iostream>


#include "Solution.hpp"
#include "Question.hpp"
#include "TestCases.hpp"
#include "../Utils/Utils.hpp"


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