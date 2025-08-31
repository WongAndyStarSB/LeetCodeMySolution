#ifndef Q8_SOLUTION_HPP
#define Q8_SOLUTION_HPP

// MySolution1

// time complexity: O(N)
// space complexity: O(1)
// time used: ~0ms
// space used: ~9MB

#include <vector>
#include <stdexcept>

using namespace std;


class Solution {
public:
    int myAtoi(string s) {
        static int MAX = 2147483647;
        static int MAX_DIV_TEN = MAX / 10;
        size_t s_size = s.size();
        int8_t sign = 1;
        bool started = false;
        int result = 0;
        for (size_t i = 0; i < s_size; ++i) {
            if (s[i] == '+') {
                if (started) { break; }
                started = true;
            } else if (s[i] == '-') {
                if (started) { break; }
                started = true;
                sign = -1;
            } else if (s[i] >= '0' && s[i] <= '9') {
                started = true;
                int digit = s[i] - '0';
                if (result > MAX_DIV_TEN
                    || ((result == MAX_DIV_TEN) && (digit > 7))
                    // digit = >7, sign=1, -> 7 
                    // digit = 8 or >8, sign=-1, -> 8
                    // digit = 7, sign=1, -> 7 (not handled here but the line after if)
                ) {
                    return (sign == 1) ? (MAX) : (-MAX-1);
                }
                result = result * 10 + digit;
            } else if (s[i] == ' ') {
                if (started) { break; }
            } else {
                break;
            }
        }
        return result * sign;
    }
};

#endif // Q8_SOLUTION_HPP