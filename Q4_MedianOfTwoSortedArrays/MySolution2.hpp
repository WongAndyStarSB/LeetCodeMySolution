#ifndef Q4_SOLUTION_HPP
#define Q4_SOLUTION_HPP

// MySolution2

// this solution is written after reading the editorial solution 2

// time complexity: 
// space complexity: 
// time used: 
// space used: 

#include <vector>
#include <stdexcept>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int ns1_size = nums1.size(), ns2_size = nums2.size();
        int total_size = ns1_size + ns2_size;
        if (total_size % 2) {
            return findTheNSmallestNumberInSortedArrays(
                nums1, nums2, (total_size) / 2,
                0, ns1_size - 1,
                0, ns2_size - 1
            );
        } else {
            return 1.0 * (
                findTheNSmallestNumberInSortedArrays(
                    nums1, nums2, (total_size) / 2,
                    0, ns1_size - 1,
                    0, ns2_size - 1
                ) + findTheNSmallestNumberInSortedArrays(
                    nums1, nums2, (total_size) / 2 + 1,
                    0, ns1_size - 1,
                    0, ns2_size - 1
                )
            ) / 2;
        }
    }
    int findTheNSmallestNumberInSortedArrays(
        vector<int>& nums1, vector<int>& nums2, int n, 
        int nums1_begin_i, int nums1_end_i,
        int nums2_begin_i, int nums2_end_i
    ) {
        if (nums1_end_i < nums1_begin_i) {
            return nums2[ n - nums1_begin_i ];
        }
        if (nums2_end_i < nums2_begin_i) {
            return nums1[ n - nums2_begin_i ];
        }
        int nums1_med_i = (nums1_begin_i + nums1_end_i) / 2;
        int nums2_med_i = (nums2_begin_i + nums2_end_i) / 2;
        int nums1_med_val = nums1[nums1_med_i];
        int nums2_med_val = nums2[nums2_med_i];

        if (nums1_med_i + nums2_med_i > n) {
            if (nums2_med_val > nums1_med_val) {
                return findTheNSmallestNumberInSortedArrays(
                    nums1, nums2, n, 
                    nums1_begin_i, nums1_end_i, 
                    nums2_begin_i, nums2_med_val - 1
                );
            } else {
                return findTheNSmallestNumberInSortedArrays(
                    nums1, nums2, n, 
                    nums1_begin_i, nums1_med_val - 1, 
                    nums2_begin_i, nums2_end_i
                );
            }
        } else {
            if (nums2_med_val > nums1_med_val) {
                return findTheNSmallestNumberInSortedArrays(
                    nums1, nums2, n,
                    nums1_med_i + 1, nums1_end_i, 
                    nums2_begin_i, nums2_end_i
                );
            } else {
                return findTheNSmallestNumberInSortedArrays(
                    nums1, nums2, n, 
                    nums1_begin_i, nums1_end_i, 
                    nums2_med_i + 1, nums2_end_i
                );
            }
        }
        return -1;
    }
};

#endif // Q4_SOLUTION_HPP