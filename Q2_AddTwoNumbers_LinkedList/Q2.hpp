#ifndef Q2_HPP
#define Q2_HPP


#include "Q2_ListNode.hpp"


constexpr int MAX_VALID_VALUE = 10;

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

void deleteArrOfLinkedListWithArrOfHead(ListNode** arr_of_heads, size_t arr_len) {
    if (arr_of_heads == nullptr) return;
    for (int i = 0; i < arr_len; ++i) {
        if (arr_of_heads[i] != nullptr) {
            deleteLinkedListWithHeadNode(arr_of_heads[i]);
        }
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

#endif // Q2_HPP