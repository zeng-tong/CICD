//
// Created by tong zeng on 2018/6/29.
//
#include <iostream>
#include <sstream>
#include <vector>
#include "ListNode"
using namespace std;

/*
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
}*/

class Solution {
public:
    static ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        ListNode dummyNode(1);
        dummyNode.next = head;
        auto pre = &dummyNode;
        while (pre && pre->next) {
            auto current = pre->next;
            auto nextNotSame = getNextNotSame(current);
            if (current->next != nextNotSame) {
                removeNodes(pre, nextNotSame);
            } else {
                pre = pre->next;
            }
        }
        return dummyNode.next;
    }

private:
    static ListNode* getNextNotSame(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        auto current = head;
        while(current && current->val == head->val) {
            current = current->next;
        }
        return current;
    }
    static void removeNodes(ListNode* pre, ListNode* end) {
        if (pre == nullptr)
            return;
        while (pre->next != end) {
            if (pre->next == nullptr) {
                return;
            }
            auto current = pre->next;
            auto tmp = current->next;
            delete current;
            pre->next = tmp;
        }
    }
};

int main() {
    string lists;
    while(getline(cin, lists)) {
        auto head = readList(lists);
        printList(Solution::deleteDuplicates(head));
    }
}