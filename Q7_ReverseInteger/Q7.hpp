#ifndef Q7_HPP
#define Q7_HPP


#include <vector>
#include <string>

#include "../Utils/StringUtils.hpp"


#ifdef Q7_CPP
    #include "MySolution1.hpp"
    #define Q7_HPP_VALID_SOURCE 1
    #define THINGS_DEFINED 1
#else
#ifdef GENERAL_RUNNER_CPP
    #include "../Q0/Solution.hpp"
    #define Q7_HPP_VALID_SOURCE 1
    #define THINGS_DEFINED 1
#else 
    #define Q7_HPP_VALID_SOURCE 0
    #define THINGS_DEFINED 0
#endif
#endif

#if Q7_HPP_VALID_SOURCE

class Question {

private:
    int32_t m_q;
    int32_t m_correct_ans;
public:
    inline explicit Question() {}

    inline explicit Question(
        const int32_t& q, const int32_t& correct_ans
    ) : m_q(q), m_correct_ans(correct_ans) 
    {}
    int32_t solve(Solution& solution) {
        return solution.reverse(m_q);
    }
    std::string toString() const {
        return 
            "q:\n  " 
            + std::to_string(m_q) + "\ncorrect_ans:\n  " 
            + std::to_string(m_correct_ans) + "\n"
        ;
    }
    std::string QAtoString(int32_t ans) const {
        return toString() + "yr_ans:\n  " + std::to_string(ans) + "\n";
    }

    static std::string staticToString(const Question& q) {
        return q.toString();
    }
};

#include "TestCases.hpp"

#endif // Q7_HPP_VALID_SOURCE

#endif //Q7_HPP