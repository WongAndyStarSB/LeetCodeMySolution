#ifndef ADD_TWO_NUMBERS_CPP
#define ADD_TWO_NUMBERS_CPP

#include <initializer_list>
#include <stdint.h>
#include <string>
#include <iostream>
#include <stdexcept>

#include "AddTwoNumbers_LinkedList.hpp"

std::string linkedListToString(const ListNode* const & arg_l) {
    std::string s = "[ ";
    for (const ListNode *current = arg_l; current != nullptr; current = current->next) {
        s += std::to_string(current->val) + (current->next == nullptr? "" : ", ");
    }
    s += " ]\n";
    return s;
}

class Question {
public:
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;
    Question(
        const std::initializer_list<uint8_t>& data1,
        const std::initializer_list<uint8_t>& data2
    ) {
        static auto func = [](const std::initializer_list<uint8_t>& d, ListNode *& l) {
            ListNode *tmp = nullptr;
            for (auto it = d.end() - 1; it != d.begin(); --it) {
                tmp = new ListNode{ *it, tmp };
            }
            l = new ListNode{ *d.begin(), tmp }; 
        };
        func(data1, l1);
        func(data2, l2);
    }
    std::string toString() const {
        if (l1 == nullptr || l2 == nullptr) {
            throw std::logic_error("NullPointerException");
        }
        
        std::string result_s = 
            linkedListToString(l1)
            + linkedListToString(l2);
        return result_s;
    }

};


#include "LeetCodeSolution.inl"

int main() {
    std::cout << "AddTwoNumbers\n";
    try {
        Question q[] = { 
            {{2, 4, 3}, {5, 6, 4}}, 
            {{0}, {0}},
            {{9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}},
            {{0}, {1}},
            {{10}, {10}}
        };
        Solution s;
        ListNode* ans;
        std::string output_str = "";
        for (int i = 0; q[i].l1->val < 10; ++i) {
            ListNode* ans = s.addTwoNumbers(q[i].l1, q[i].l2);
            output_str += 
                "q:\n" + q[i].toString() 
                + "ans\n" + linkedListToString(ans) + "\n";
        }
        std::cout << output_str;
    } catch (std::exception& e) {
        std::cerr << e.what();
    }
    return 0;
}
#endif // ADD_TWO_NUMBERS_CPP