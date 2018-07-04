//
// Created by tong zeng on 2018/6/29.
//
#include <iostream>
#include <sstream>
#include <vector>
#include "ListNode"
using namespace std;

class Solution {
public:
    static ListNode* deleteDuplication(ListNode* pHead) {
        if (pHead == nullptr)
            return nullptr;
        auto dummy = new ListNode(0); dummy->next = pHead;
        auto pre = dummy;
        while(pre->next && pre->next->next) {
            if (pre->next->val == pre->next->next->val) {
                auto nextNotSame = getNextNotSame(pre->next);
                while(pre->next != nextNotSame) {
                    auto tmp = pre->next->next;
                    delete pre->next;
                    pre->next = tmp;
                }
            }else {
                pre = pre->next;
            }
        }
        return dummy->next;
    }

private:
    static ListNode* getNextNotSame(ListNode* pHead) {
        if (pHead == nullptr)
            return nullptr;
        auto pNext = pHead->next;
        while(pNext && pNext->val == pHead->val) pNext = pNext->next;
        return pNext;
    }
};
int main() {
    string str;
    while (getline(cin, str)) {
        auto root = readList(str);
        printList(Solution::deleteDuplication(root));
    }
    return 0;
}