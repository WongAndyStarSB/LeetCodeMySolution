#ifndef Q5_SOLUTION_HPP
#define Q5_SOLUTION_HPP

// MySolution1

// time complexity: O(N^3)
// space complexity: O(1) // not counting answer
// time used: ~80ms
// space used: ~9.5MB

#include <vector>
#include <stdexcept>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        size_t s_size = s.size();
        for (int l = s_size-1; l >= 0; --l) {
            for (int i = 0; i < s_size-l; ++i) {
                if (isPalindromic(s, i, i+l)) {
                    return s.substr(i, l+1);
                }
            }
        }
        throw;
    }
private:
    bool isPalindromic(const string& s, int i_begin, int i_last) {
        while (i_begin < i_last) {
            if (s[i_begin] != s[i_last]) {
                return false;
            }
            i_begin++;
            i_last--;
        }
        return true;
    }
};

#endif // Q5_SOLUTION_HPP