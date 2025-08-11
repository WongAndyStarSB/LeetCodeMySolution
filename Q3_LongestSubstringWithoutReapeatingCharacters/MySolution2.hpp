#ifndef Q3_SOLUTION_2_HPP
#define Q3_SOLUTION_2_HPP


#include "Q3.hpp"

// sliding window

// time complexity: --
// space complexity: --
// time used: ~0ms
// space used: 10.0MB ~ 10.5MB

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int L = 0;
        int R = 0;
        int return_length = 0;
        while (R < s.size()) {
            ++R;
            bool will_duplicate = false;
            int i = L;
            if (R < s.size()) {
                for ( ; i < R; ++i) {
                    if (s[R] == s[i]) {
                        will_duplicate = true;
                        break;
                    }
                }
            }
            if (will_duplicate || R == s.size()) {
                if (R-L > return_length) {
                    return_length = R-L;
                }
                L = i + 1;
            }
        }
        return return_length;
    }
};

#endif // Q3_SOLUTION_2_HPP