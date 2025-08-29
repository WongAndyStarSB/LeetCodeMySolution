#ifndef TEST_CASES_HPP
#define TEST_CASES_HPP


#include "Q7.hpp"

#if Q7_HPP_VALID_SOURCE

const size_t TEST_CASES_LEN = 5;
const Question TEST_CASES[TEST_CASES_LEN] {
    Question{ (int32_t) 123,        (int32_t)321  },
    Question{ (int32_t)-123,        (int32_t)-321 },
    Question{ (int32_t) 120,        (int32_t)21   },
    Question{ (int32_t) 2147483647, (int32_t)0    },
    Question{ (int32_t)-2147483648, (int32_t)0    }
};

#endif

#endif // TEST_CASES_HPP