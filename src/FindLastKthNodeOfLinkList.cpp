// 
// Created by tong zeng on 2018/7/10 8:42 AM.
//
#include "ListNode"
#include "commonHeader"

class Solution {
public:
    static ListNode *FindKthToTail(ListNode *head, int k) {
        ListNode *faster = head, *slower = head;
        while (faster && k--)
            faster = faster->next;
        if (k > 0) return nullptr;
        while (faster) {
            faster = faster->next;
            slower = slower->next;
        }
        return slower;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        auto head = readList(line);
        printList(Solution::FindKthToTail(head, 1));
    }
    return 0;
}