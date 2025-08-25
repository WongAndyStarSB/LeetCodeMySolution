#ifndef Q5_SOLUTION_HPP
#define Q5_SOLUTION_HPP

// MySolution1

// time complexity: O(N^2)
// space complexity: O(1) // not counting answer
// time used: ~15ms
// space used: 18MB ~ 19MB

#include <string>
#include <vector>
#include <array>
#include <stdexcept>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int s_size = s.size();
        string ans;
        for (int i = 0; i < s_size; ++i) {
            string odd = m_expand(s, i, i);
            if (odd.size() > ans.size()) {
                ans = odd;
            }
            string even = m_expand(s, i, i+1);
            if (even.size() > ans.size()) {
                ans = even;
            }
        }
        return ans;
    }
private:
    string m_expand(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return s.substr(left + 1, right - left + 1 - 2);
    }
};

#endif // Q5_SOLUTION_HPP