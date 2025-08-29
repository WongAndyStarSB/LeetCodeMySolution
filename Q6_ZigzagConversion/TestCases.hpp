#ifndef TEST_CASES_HPP
#define TEST_CASES_HPP


#include "Q6.hpp"

#if Q6_HPP_VALID_SOURCE

const size_t TEST_CASES_LEN = 4;
const Question TEST_CASES[TEST_CASES_LEN] {
    Question{ "PAYPALISHIRING" , 3 , "PAHNAPLSIIGYIR" },
    Question{ "PAYPALISHIRING" , 4 , "PINALSIGYAHRPI" },
    Question{ "A" , 1 , "A" },
    Question{ "ABCD", 3, "ABDC"}
};

#endif

#endif // TEST_CASES_HPP