#ifndef Q6_SOLUTION_HPP
#define Q6_SOLUTION_HPP

// MySolution1

// time complexity: O(N^2)
// space complexity: O(1) // not counting answer
// time used: ~3ms
// space used: ~10.5MB

#include <vector>
#include <stdexcept>

using namespace std;


class Solution {
public:
    string convert(const string& s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        size_t s_size = s.size();
        string return_s (s_size, '-');
        int ret_s_i = 0;
        size_t rn = 0;
        size_t i = 0;
        while (rn < numRows) {
            int peak = rn << 1;
            int trough = (numRows - rn - 1) << 1; // (numRows - rn) * 2 - 2
            i = rn;
            return_s[ret_s_i++] = s[i];
            while (true) {
                if (trough) {
                    i += trough;
                    if (i < s_size) {
                        return_s[ret_s_i++] = s[i];
                    } else { 
                        break; 
                    }
                }
                if (peak) {
                    i += peak;
                    if (i < s_size) {
                        return_s[ret_s_i++] = s[i];
                    } else { 
                        break; 
                    }
                }
            }
            ++rn;
        }
        return return_s;
    }
};

#endif // Q6_SOLUTION_HPP