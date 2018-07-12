//
// Created by tong zeng on 2018/7/12 6:58 PM.
//

#include "RandomListHelper"

class Solution {
public:
    // O(n) time, O(n) space
    RandomListNode *copyRandomList(RandomListNode *head) {
        auto res = onlyCopy(head);
        initRandom(head, res);
        return res;
    }

private:
    RandomListNode *onlyCopy(RandomListNode *head) {
        if (head == nullptr) return head;
        auto current = new RandomListNode(head->label);
        auto result = current;
        record[head] = current;

        head = head->next;
        while (head) {
            current->next = new RandomListNode(head->label);
            record[head] = current->next;
            head = head->next;
            current = current->next;
        }
        return result;
    }

    void initRandom(RandomListNode *origin, RandomListNode *cpy) {
        record[nullptr] = nullptr;
        while (origin) {
            cpy->random = record[origin->random];
            cpy = cpy->next;
            origin = origin->next;
        }
    }

private:
    typedef RandomListNode *ORIGIN_NODE;
    typedef RandomListNode *NEW_NODE;
    unordered_map<ORIGIN_NODE, NEW_NODE> record;
};
