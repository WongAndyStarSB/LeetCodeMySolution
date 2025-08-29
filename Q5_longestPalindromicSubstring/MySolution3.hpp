#ifndef Q5_SOLUTION_HPP
#define Q5_SOLUTION_HPP

// MySolution3 (LeetCodeEditorial_2)

// time complexity: O(N^2)
// space complexity: O(N^2) // not counting answer
// time used: ~110ms
// space used: ~26MB

#include <vector>
#include <array>
#include <stdexcept>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        size_t n = s.size();
        std::array<int, 2> ans { 0, 0 };
        std::vector<std::vector<bool>> table (n, std::vector<bool>(n, false));

        for (int i = 0; i < n; ++i) {
            table[i][i] = true;
        }
        for (int i = 0; i < n-1; ++i) {
            if (s[i] == s[i+1]) {
                table[i][i+1] = true;
                ans = {i, i+1};
            }
        }
        for (int diff = 2; diff < n; ++diff) {
            for (int i = 0; i < n - diff; ++i) {
                int j = i + diff;
                if (s[i] == s[j] 
                    && table[i + 1][j - 1]
                ) {
                    table[i][j] = true; 
                    ans = {i, j};
                }
            }
        }
        int i = ans[0];
        return s.substr(i, ans[1]-i+1);
    }
};

#endif // Q5_SOLUTION_HPP