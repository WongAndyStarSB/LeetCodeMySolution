#ifndef TEST_CASES_HPP
#define TEST_CASES_HPP


#include "Q4.hpp"

const size_t TEST_CASES_LEN = 9;
const Question TEST_CASES[TEST_CASES_LEN] {
    Question{ {1, 3}, {2} },
    Question{ {1, 2}, {3, 4} }, 
    Question{ {0, 0}, {0, 0} },
    Question{ {-1, -1}, {-1, -1} },
    Question{ {0, 1000000}, {1000000, 1000000} },
    Question{ {-3, -2}, {-1, 0} },
    Question{ {-1}, {-1} },
    Question{ {99}, {} },
    Question{ {}, {1000000} }
};

#endif // TEST_CASES_HPP