// 
// Created by tong zeng on 2018/7/10 9:51 AM.
//
#include "ListNode"
#include "commonHeader"

class Solution {
public:
    static ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
        if (!pHead1) return pHead2;
        if (!pHead2) return pHead1;
        ListNode dummy(0);
        dummy.next = pHead1;
        auto pre = &dummy, current = pHead1;
        while (pHead2) {
            if (current == nullptr) {
                pre->next = pHead2;
                break;
            } else if (current->val >= pHead2->val) {
                auto pHead2Next = pHead2->next;
                pre->next = pHead2;
                pHead2->next = current;
                pHead2 = pHead2Next;
                pre = pre->next;
            } else {
                pre = pre->next;
                current = current->next;
            }
        }
        return dummy.next;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        string line2;
        getline(cin, line2);
        auto head1 = readList(line);
        auto head2 = readList(line2);
        printList(Solution::Merge(head1, head2));
    }
    return 0;
}
