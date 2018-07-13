// 
// Created by tong zeng on 2018/7/13 10:00 AM.
//
#include "ListNode"
#include "commonHeader"

class Solution {
public:
    static ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto first = headA, second = headB;
        while (first != second) {
            first = first == nullptr ? headB : first->next;
            second = second == nullptr ? headA : second->next;
        }
        return first;
    }
};

ListNode* getLastNode(ListNode* head) {
    while (head->next) {
        head = head->next;
    }
    return head;
}

int main() {
    string line;
    while (getline(cin, line)) {
        auto common = readList("4,52,59,90,76,89");
        auto headA = readList(line);
        getline(cin, line);
        auto headB = readList(line);
        getLastNode(headA)->next = common;
        getLastNode(headB)->next = common;
        auto res = Solution::getIntersectionNode(headA, headB);
        cout << res->val << endl;
    }
    return 0;
}