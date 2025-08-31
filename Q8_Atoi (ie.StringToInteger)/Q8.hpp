#ifndef Q8_HPP
#define Q8_HPP


#include <vector>
#include <string>

#include "../Utils/StringUtils.hpp"


#ifdef Q8_CPP
    #include "MySolution1.hpp"
    #define Q8_HPP_VALID_SOURCE 1
    #define THINGS_DEFINED 1
#else
#ifdef GENERAL_RUNNER_CPP
    #include "../Q0/Solution.hpp"
    #define Q8_HPP_VALID_SOURCE 1
    #define THINGS_DEFINED 1
#else 
    #define Q8_HPP_VALID_SOURCE 0
    #define THINGS_DEFINED 0
#endif
#endif

#if Q8_HPP_VALID_SOURCE

class Question {

private:
    std::string m_q;
    int m_correct_ans;
public:
    inline explicit Question() {}

    inline explicit Question(
        const std::string& q, const int& correct_ans
    ) : m_q(q), m_correct_ans(correct_ans) 
    {}
    int solve(Solution& solution) {
        return solution.myAtoi(m_q);
    }
    std::string toString() const {
        return 
            "q:\n  \"" 
            + m_q + "\"\ncorrect_ans:\n  " 
            + std::to_string(m_correct_ans) + "\n"
        ;
    }
    std::string QAtoString(int ans) const {
        return toString() + "yr_ans:\n  " + std::to_string(ans) + "\n";
    }

    static std::string staticToString(const Question& q) {
        return q.toString();
    }
};

#include "TestCases.hpp"

#endif // Q8_HPP_VALID_SOURCE

#endif //Q8_HPP