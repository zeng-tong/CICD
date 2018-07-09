// 
// Created by tong zeng on 2018/7/9 10:44 PM.
//

#include "commonHeader"
#include "ListNode"

class Solution {
public:
    static ListNode *reverseList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *pre = nullptr, *current = head, *later = head->next;
        while (later) {
            current->next = pre;
            pre = current;
            current = later;
            later = later->next;
        }
        current->next = pre;
        return current;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        auto root = readList(line);
        printList(Solution::reverseList(root));
    }
    return 0;
}