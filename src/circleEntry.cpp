//
// Created by tong zeng on 2018/7/1.
//
#include <iostream>
#include <string>
#include "ListNode"
using namespace std;

class Solution {
public:
    static ListNode* EntryNodeOfLoop(ListNode* pHead){
        if (pHead == nullptr || pHead->next == nullptr)
            return nullptr;
        auto slower = pHead->next;
        auto faster = pHead->next->next;
        while(faster != slower) {
            if (faster == nullptr || faster->next == nullptr) return nullptr;
            faster = faster->next->next;
            slower = slower->next;
        }
        faster = pHead;
        while(faster != slower) {
            faster = faster->next;
            slower = slower->next;
        }
        return faster;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("usage: %s circle_entry_pos", argv[0]);
        exit(1);
    }
    string lists;
    getline(cin, lists);
    auto pHead = readList(lists);

    auto circleEntry = pHead;
    auto tmp = pHead;
    int pos = 1;
    while (tmp->next) {
        if (pos == atoi(argv[1])) circleEntry = tmp;
        tmp = tmp->next;
        ++pos;
    }
    tmp->next = circleEntry;

    auto res = Solution::EntryNodeOfLoop(pHead);

    assert(res == circleEntry);
    return 0;
}


