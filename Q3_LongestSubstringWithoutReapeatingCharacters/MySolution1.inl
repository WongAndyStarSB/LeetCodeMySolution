#ifndef Q3_SOLUTION_1_INL
#define Q3_SOLUTION_1_INL


#include "Q3.hpp"

// time complexity: O(N^3)
// space complexity: O(1)
// time used: 95ms ~ 105ms
// space used: 10.0MB ~ 10.5MB

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s.size() - i <= length) {
                return length;
            }
            int tmp_len = 1;
            for (int j = i+1; j < s.size(); ++j) {
                bool flag = true;
                for (int z = i; z < j; ++z) {
                    if (s[j] == s[z]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    tmp_len++;
                } else {
                    break;
                }
            }
            if (tmp_len > length) {
                length = tmp_len;
            }
        }
        return length;
    }
};

#endif // Q3_SOLUTION_1_INL