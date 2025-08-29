#ifndef Q6_SOLUTION_HPP
#define Q6_SOLUTION_HPP

// MySolution2

// time complexity: O(N)
// space complexity: O(N) // not counting answer
// time used: ~0ms
// space used: ~12MB

#include <vector>
#include <stdexcept>
#include <cstdlib>

using namespace std;


class Solution {
public:
    string convert(const string& s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        size_t s_size = s.size();
        string return_s (s_size, '-');
        size_t trough = (numRows-1) << 1;
        div_t size_div_trough = std::div((int)s_size, (int)trough);
        std::vector<size_t> widths;
        std::vector<size_t> sums;
        // init widths
        widths.reserve(numRows);
        for (size_t r = 0; r < numRows; ++r) {
            if (r == 0) {
                widths.emplace_back(size_div_trough.quot + (size_div_trough.rem > 0));
            } else if (r == numRows - 1) {
                widths.emplace_back(size_div_trough.quot + (size_div_trough.rem >= numRows));
            } else {
                widths.emplace_back(
                    (size_div_trough.quot << 1) // * 2
                    + (size_div_trough.rem > r) // rem = 1 means have letter in r = 0, so only >, not >=
                    + (size_div_trough.rem > trough - r) 
                    // 1.
                    // trough means len_of_trough, so it is larger for 1
                    // here, r always in (0, numRows) (exclusive)
                    // which means trough-r is valid
                    // 2.
                    // rem matches 1index (except when should == trough, it will be 0 not trough)
                    // trough-r and r is on same row, and trough-r (and r both) matches 0index
                    // so, 
                    // 0 to trough-2 (of r or trough-r) matches 1 to trough-1 (of rem)
                    // trough-1 (of r or trough-1) matches 0 of rem
                    // (we don't need when rem = 0)
                );
            }
        }
        // init sums
        sums.reserve(numRows);
        sums.emplace_back(0);
        for (size_t i = 0; i < numRows-1; ++i) {
            sums.emplace_back(sums[i] + widths[i]);
        }
        //
        for (size_t i = 0; i < s_size; ++i) {
            div_t i_div_trough = std::div((int)i, (int)trough);
            size_t r = (i_div_trough.rem < numRows) ? (i_div_trough.rem) : (trough - i_div_trough.rem);
            size_t c;
            if (i_div_trough.rem == 0 || i_div_trough.rem == numRows - 1) {
                c = (i_div_trough.quot);
            } else {
                c = (
                    (i_div_trough.quot << 1) + 
                    (i_div_trough.rem >= numRows) // rem = row_index + 1, numRows = largest_row_index + 1, so >=
                );
            }
            return_s[sums[r] + c] = s[i];
        }
        return return_s;
    }
};

#endif // Q6_SOLUTION_HPP