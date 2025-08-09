#ifndef ADD_TWO_NUMBERS_HPP
#define ADD_TWO_NUMBERS_HPP

#include <initializer_list>
#include <stdint.h>
#include <string>
#include <iostream>
#include <stdexcept>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

#endif // ADD_TWO_NUMBERS_HPP