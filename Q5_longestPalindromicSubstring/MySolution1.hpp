#ifndef Q5_SOLUTION_HPP
#define Q5_SOLUTION_HPP

// MySolution1

// time complexity: 
// space complexity: 
// time used: 105ms ~ 110ms 
// space used: 9.0MB ~ 10.0MB

#include <vector>
#include <stdexcept>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size() ;
        for (int l = size; l > 0; l--) {
            for (int i = 0; i <= size-l; ++i) {
                bool is_pldmic = true;
                for (int j = 0; j < l/2; ++j) {
                    if (s[i+j] != s[i+l-j-1] ) {
                        is_pldmic = false;
                        break;
                    }
                }
                if (is_pldmic) {
                    return s.substr(i, l);
                }
            }
        }
        throw;
    }
};

#endif // Q5_SOLUTION_HPP