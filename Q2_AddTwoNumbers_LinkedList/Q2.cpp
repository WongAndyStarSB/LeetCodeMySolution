#include <initializer_list>
#include <stdint.h>
#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>

#include "Q2.hpp"


#include "LeetCodeSolution.inl"

int main() {
    try {
        std::cout << "AddTwoNumbers\n";
        #include "TestCases.hpp"
        const auto &q = TEST_CASES;
        Solution s;
        ListNode* anss[TEST_CASES_LEN];
        std::stringstream ss;
        for ( int i = 0; i < TEST_CASES_LEN; ++i) {
            if (!q[i].l1 || !q[i].l2) {
                throw std::logic_error("q[i].l1 || q[i].l2 is nullptr");
            }
            if (q[i].l1->val == MAX_VALID_VALUE && q[i].l2->val == MAX_VALID_VALUE) {
                break;
            }
            anss[i] = s.addTwoNumbers(q[i].l1, q[i].l2);
            ss << 
                "q:\n" << q[i].toString() 
                << "ans\n" << linkedListToString(anss[i]) << "\n";
        }

        std::cout << ss.str();

        deleteArrOfLinkedListWithArrOfHead(anss, TEST_CASES_LEN);
        // q->~Question(); // auto call after main, so don't call manually

        std::cout << "goodbye\n";
    } catch (std::exception& e) {
        std::cout << "Error Caught:\n";
        std::cerr << e.what();
        return 1;
    }
    return 0;
}
