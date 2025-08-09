#ifndef ADD_TWO_NUMBERS_SOLUTION_2_INL
#define ADD_TWO_NUMBERS_SOLUTION_2_INL

#include "AddTwoNumbers_LinkedList.hpp"

// this solution has 
// time-complexity: O(Max(M,N))
// time used: 0~3 ms
// space-complexity: O(Max(M,N))
// space used: ~77 MB

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
        bool add1 = false;
        int sum = 0;

        sum = l1->val + l2->val + add1;
        if (sum > 9) {
            sum -= 10;
            add1 = true;
        } else {
            add1 = false;
        }
        ListNode* l3 = new ListNode{ sum }; // this should be the one we will finally return
        ListNode* current_l1 = l1->next;
        ListNode* current_l2 = l2->next;
        ListNode* last_l3 = l3;
        while (true) {
            if (current_l1 == nullptr && current_l2 == nullptr) {
                if (add1) {
                    last_l3->next = new ListNode{ 1 };
                } else {
                    last_l3->next = nullptr;
                }
                return l3;
            }
            int l1_val = 0;
            int l2_val = 0;
            if (current_l1) {
                l1_val = current_l1->val;
                current_l1 = current_l1->next;
            }
            if (current_l2) {
                l2_val = current_l2->val;
                current_l2 = current_l2->next;
            }

            sum = l1_val + l2_val + add1;
            if (sum > 9) {
                sum -= 10;
                add1 = true;
            } else {
                add1 = false;
            }
            ListNode* current_l3 = new ListNode { sum };
            last_l3->next = current_l3;
            last_l3 = current_l3;
        }
    }
};

#endif // ADD_TWO_NUMBERS_SOLUTION_2_INL