#ifndef Q2_SOLUTION_1_INL
#define Q2_SOLUTION_1_INL

#include "Q2_ListNode.hpp"

// this solution has 
// time-complexity: --
// time used: 0.2 ms
// space-complexity: --
// space used: 77.16 MB

/*
* // Definition for singly-linked list.
* struct ListNode {
*    int val;
*    ListNode *next;
*    ListNode() : val(0), next(nullptr) {}
*    ListNode(int x) : val(x), next(nullptr) {}
*    ListNode(int x, ListNode *next) : val(x), next(next) {}
* }
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        static bool add1 = false;

        
        if (l1 == nullptr && l2 == nullptr) {
            if (add1) {
                add1 = false; // set back to false for other subsequent tests
                return new ListNode{ 1, nullptr };
            } else {
                return nullptr;
            }
        }

        int l1_val = 0;
        int l2_val = 0;
        ListNode* l1_next = nullptr;
        ListNode* l2_next = nullptr;
        if (l1 != nullptr) {
            l1_val = l1->val;
            l1_next = l1->next;
        }
        if (l2 != nullptr) {
            l2_val = l2->val;
            l2_next = l2->next;
        }
        int sum = l1_val + l2_val + add1;
        if (sum > 9) { 
            sum -= 10;
            add1 = true;
        } else {
            add1 = false;
        }
        return new ListNode{ sum, addTwoNumbers(l1_next, l2_next) };
    }
};

#endif // Q2_SOLUTION_1_INL