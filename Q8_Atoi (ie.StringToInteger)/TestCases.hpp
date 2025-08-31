#ifndef TEST_CASES_HPP
#define TEST_CASES_HPP


#include "Q8.hpp"

#if Q8_HPP_VALID_SOURCE

const size_t TEST_CASES_LEN = 7;
const Question TEST_CASES[TEST_CASES_LEN] {
    Question{ "42"           , (int) 42   },
    Question{ "   -042"      , (int)-42   },
    Question{ "1337c0d3"     , (int) 1337 },
    Question{ "0-1"          , (int) 0    },
    Question{ "words and 987", (int) 0    },
    Question{ "+-123"        , (int) 0    },
    Question{ "12 36"        , (int) 12   }
};

#endif

#endif // TEST_CASES_HPP