#ifndef Q5_SOLUTION_HPP
#define Q5_SOLUTION_HPP

// MySolution1

// time complexity: O(N)
// space complexity: O(1)
// time used: -
// space used: -

#include <string>
#include <vector>
#include <array>
#include <stdexcept>

using namespace std;


class Solution {
public:
    string longestPalindrome(string s) {
        string s_prime = "#";
        for (char c : s) {
            s_prime += c;
            s_prime += "#";
        }

        int n = s_prime.size();
        vector<int> palindrome_radii(n, 0);
        int center = 0;
        int radius = 0;

        for (int i = 0; i < n; i++) {
            int mirror = 2 * center - i;

            if (i < radius) {
                palindrome_radii[i] = min(radius - i, palindrome_radii[mirror]);
            }

            while (
                i + 1 + palindrome_radii[i] < n 
                && i - 1 - palindrome_radii[i] >= 0 
                && s_prime[i + 1 + palindrome_radii[i]] ==
                    s_prime[i - 1 - palindrome_radii[i]]
            ) {
                palindrome_radii[i]++;
            }

            if (i + palindrome_radii[i] > radius) {
                center = i;
                radius = i + palindrome_radii[i];
            }
        }

        int max_length = 0;
        int center_index = 0;
        for (int i = 0; i < n; i++) {
            if (palindrome_radii[i] > max_length) {
                max_length = palindrome_radii[i];
                center_index = i;
            }
        }

        return s.substr(
            (center_index - max_length) / 2, // start index
            max_length
        );
    }
};

#endif // Q5_SOLUTION_HPP