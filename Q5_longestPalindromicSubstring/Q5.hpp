#ifndef Q5_HPP
#define Q5_HPP


#include <vector>
#include <string>

#include "../Utils/StringUtils.hpp"


#ifdef Q5_CPP
    #include "Manacher's_Algorithm.hpp"
    #define Q5_HPP_VALID_SOURCE 1
    #define THINGS_DEFINED 1
#else
#ifdef GENERAL_RUNNER_CPP
    #include "../Q0/Solution.hpp"
    #define Q5_HPP_VALID_SOURCE 1
    #define THINGS_DEFINED 1
#else 
    #define Q5_HPP_VALID_SOURCE 0
    #define THINGS_DEFINED 0
#endif
#endif

#if Q5_HPP_VALID_SOURCE

class Question {

private:
    std::string m_s;
public:
    inline explicit Question() {}

    inline explicit Question(
        std::string s
    ) : m_s(s) 
    {}
    std::string solve(Solution& solution) {
        return solution.longestPalindrome(m_s);
    }
    std::string toString() const {
        return 
            "q:\n" 
            + m_s + "\n"
        ;
    }
    std::string QAtoString(std::string ans) const {
        return toString() + "ans:\n" + ans + "\n";
    }

    static std::string staticToString(const Question& q) {
        return q.toString();
    }
};

#include "TestCases.hpp"

#endif // Q5_HPP_VALID_SOURCE

#endif //Q5_HPP