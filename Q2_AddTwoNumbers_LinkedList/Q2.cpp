#include <initializer_list>
#include <stdint.h>
#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>

#include "Q2.hpp"

    
std::string linkedListToString(const ListNode* const & arg_l) {
    std::string s = "[ ";
    for (const ListNode *current = arg_l; current != nullptr; current = current->next) {
        s += std::to_string(current->val) + (current->next == nullptr? "" : ", ");
    }
    s += " ]\n";
    return s;
}

void deleteLinkedListWithHeadNode(ListNode*& head) {
    ListNode* l = head;
    while (l) {
        ListNode* next = l->next;
        delete l;
        l = next;
    }
    head = nullptr;
}

void deleteArrOfLinkedListWithArrOfHead(ListNode** arr_of_heads, ListNode* end_specifier = nullptr) {
    for (int i = 0; arr_of_heads[i] != end_specifier; ++i) {
        deleteLinkedListWithHeadNode(arr_of_heads[i]);
    }
}
class Question {
public:
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;
    Question(
        const std::initializer_list<uint8_t>& data1,
        const std::initializer_list<uint8_t>& data2
    ) {
        static auto buildLinkedList = [](const std::initializer_list<uint8_t>& d, ListNode *& l) {
            ListNode *tmp = nullptr;
            for (auto it = d.end() - 1; it != d.begin(); --it) {
                tmp = new ListNode{ *it, tmp };
            }
            l = new ListNode{ *d.begin(), tmp }; 
        };
        buildLinkedList(data1, l1);
        buildLinkedList(data2, l2);
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
    ~Question() {
        deleteLinkedListWithHeadNode(l1);
        deleteLinkedListWithHeadNode(l2);
    }
};

#include "LeetCodeSolution.inl"

int main() {
    try {
        std::cout << "AddTwoNumbers\n";
        constexpr int MAX_VALID_VALUE = 10;
        Question q[] = { 
            {{2, 4, 3}, {5, 6, 4}}, 
            {{0}, {0}},
            {{9, 9, 9, 9, 9, 9, 9}, {9, 9, 9, 9}},
            {{0}, {1}},
            {{MAX_VALID_VALUE}, {MAX_VALID_VALUE}}
        };
        Solution s;
        ListNode* anss[sizeof(q)];
        std::stringstream ss;
        for (int i = 0; q[i].l1 && q[i].l1->val < MAX_VALID_VALUE; ++i) {
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

        deleteArrOfLinkedListWithArrOfHead(anss);
    } catch (std::exception& e) {
        std::cout << "Error Caught:\n";
        std::cerr << e.what();
        return 1;
    }
    return 0;
}
