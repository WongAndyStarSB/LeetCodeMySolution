#ifndef Q4_HPP
#define Q4_HPP


#include <vector>
#include <string>

#include "../Utils/StringUtils.hpp"
#include "Solution.hpp"

class Question {
    
using SolutionFuncPtrT = double (*)(std::vector<int>, std::vector<int>);

private:
    std::vector<int> nums1;
    std::vector<int> nums2;
public:
    inline explicit Question() {}

    inline explicit Question(
        const std::initializer_list<int>& il1, const std::initializer_list<int>& il2
    ) : nums1(il1), nums2(il2) 
    {}
    double solve(Solution& solution) {
        return solution.findMedianSortedArrays(nums1, nums2);
    }
    std::string toString() const {
        return 
            "q:\n" 
            + StringUtils::arrToStr(nums1.begin(), nums1.end()) 
            + StringUtils::arrToStr(nums2.begin(), nums2.end())
        ;
    }
    std::string QAtoString(double ans) const {
        return toString() + "ans:\n" + std::to_string(ans) + "\n";
    }

    static std::string staticToString(const Question& q) {
        return q.toString();
    }
};

#include "TestCases.hpp"

#endif //Q4_HPP