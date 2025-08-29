#ifndef Q7_SOLUTION_HPP
#define Q7_SOLUTION_HPP

// MySolution1

// time complexity: O(len_of_x)
// space complexity: O(1)
// time used: ~0ms
// space used: ~8.62MB

#include <vector>
#include <stdexcept>

using namespace std;


class Solution {
public:
    int reverse(int32_t x) {
        int32_t result = 0;
        div_t div_result = {x, 0};
        int32_t MAX_DIV_TEN = 214748364; // 2147483648
        while (div_result.quot != 0) {
            div_result = std::div(div_result.quot, 10);
            if (
                result > MAX_DIV_TEN 
//              || (result == MAX_DIV_TEN && div_result.rem > 7)
                || result < -MAX_DIV_TEN 
//              || (result == -MAX_DIV_TEN && div_result.rem < -8)
            )
                return 0;
            result = result * 10 + div_result.rem;
        }
        return result;
    }
};

#endif // Q7_SOLUTION_HPP