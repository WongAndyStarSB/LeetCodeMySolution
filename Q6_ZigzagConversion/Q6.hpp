#ifndef Q6_HPP
#define Q6_HPP


#include <vector>
#include <string>

#include "../Utils/StringUtils.hpp"


#ifdef Q6_CPP
    #include "MySolution3.hpp"
    #define Q6_HPP_VALID_SOURCE 1
    #define THINGS_DEFINED 1
#else
#ifdef GENERAL_RUNNER_CPP
    #include "../Q0/Solution.hpp"
    #define Q6_HPP_VALID_SOURCE 1
    #define THINGS_DEFINED 1
#else 
    #define Q6_HPP_VALID_SOURCE 0
    #define THINGS_DEFINED 0
#endif
#endif

#if Q6_HPP_VALID_SOURCE

class Question {

private:
    std::string m_s;
    int m_row_n;
    std::string m_correct_ans;
public:
    inline explicit Question() {}

    inline explicit Question(
        const std::string& s, int Row_n, const std::string& correct_ans
    ) : m_s(s), m_row_n(Row_n), m_correct_ans(correct_ans) 
    {}
    std::string solve(Solution& solution) {
        return solution.convert(m_s, m_row_n);
    }
    std::string toString() const {
        return 
            "q:\n  " 
            + m_s + " , " + std::to_string(m_row_n) + "\ncorrect_ans:\n  " 
            + m_correct_ans + "\n"
        ;
    }
    std::string QAtoString(std::string ans) const {
        return toString() + "yr_ans:\n  " + ans + "\n";
    }

    static std::string staticToString(const Question& q) {
        return q.toString();
    }
};

#include "TestCases.hpp"

#endif // Q6_HPP_VALID_SOURCE

#endif //Q6_HPP