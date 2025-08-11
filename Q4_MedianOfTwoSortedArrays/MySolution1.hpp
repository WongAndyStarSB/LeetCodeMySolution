#ifndef Q4_SOLUTION_HPP
#define Q4_SOLUTION_HPP

// MySolution1

// time complexity: O(M+N)
// space complexity: O(1)
// time used: 0ms ~ 2ms
// space used: ~95MB

#include <vector>
#include <stdexcept>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t size1 = nums1.size();
        size_t size2 = nums2.size();
        size_t total_size = size1 + size2;
        int num_of_merged_when_median = total_size / 2 + total_size % 2;
        int i1 = 0, i2 = 0;
        int last_added = 0;
        int lastlast_added = INT_MAX;
        while (true) {
            if (i1 == size1) {
                last_added = nums2[i2];
                ++i2;
            } else if (i2 == size2) {
                last_added = nums1[i1];
                ++i1;
            } else if (nums1[i1] < nums2[i2]) {
                last_added = nums1[i1];
                ++i1;
            } else {
                last_added = nums2[i2];
                ++i2;
            }
            if (i1 + i2 == num_of_merged_when_median) {
                if (total_size % 2) {
                    return last_added;
                } else {
                    if (lastlast_added == INT_MAX) {
                        lastlast_added = last_added;
                        num_of_merged_when_median += 1;
                    } else {
                        return static_cast<double>(lastlast_added + last_added) / 2;
                    }
                }
            }
        }
        throw std::logic_error("UNREACHABLE CODE REACHED, findMedianSortedArrays");
    }
};

#endif // Q4_SOLUTION_HPP