#ifndef Q6_SOLUTION_HPP
#define Q6_SOLUTION_HPP

// MySolution3 

// time complexity: O(N)
// space complexity:  // not counting answer
// time used: 
// space used: 

#include <vector>
#include <array>
#include <stdexcept>

using namespace std;


class Solution {
public:
    string convert(const string& s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int velocity = 1;
        size_t s_size = s.size();
        size_t rn = 0;
        size_t i = 0;
        std::vector<std::string> s_vect (numRows, "");
        for (auto& str : s_vect) {
            str.reserve(s_size / numRows + 1);
        }
        while (i < s_size) {
            s_vect[rn].push_back(s[i]);
            velocity = 
                velocity * (rn > 0 && rn < numRows-1) 
                + (rn == 0) 
                - (rn == numRows-1);
            rn += velocity;
            ++i;
        }
        std::string ret_s;
        ret_s.reserve(s_size);
        i = 0;
        for (; i < numRows; ++i) {
            ret_s.append(s_vect[i]);
        }
        return ret_s;
    }
};

#endif // Q6_SOLUTION_HPP