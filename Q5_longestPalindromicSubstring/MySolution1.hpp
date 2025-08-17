#ifndef Q5_SOLUTION_HPP
#define Q5_SOLUTION_HPP

// MySolution1

// time complexity: 
// space complexity: 
// time used: 
// space used: 

#include <vector>
#include <stdexcept>

using namespace std;


class Solution {
public:
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
                    std::string pld_s;
                    for (int j = i; j < i+l; ++j) {
                        pld_s += s[j] ;
                    }
                    return pld_s;
                }
            }
        }
        throw;
    }
};
};

#endif // Q5_SOLUTION_HPP