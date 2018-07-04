//
// Created by tong zeng on 2018/7/1.
//
#include <iostream>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {

    }
};

class Solution {
public:
    static TreeLinkNode *GetNext(TreeLinkNode *pNode) {
        if (pNode == nullptr) return pNode;
        if (pNode->right) {
            pNode = pNode->right;
            return [&pNode]() {
                while (pNode->left) pNode = pNode->left;
                return pNode;
            }();
        } else if (pNode->next == nullptr) return nullptr; // 根节点，且无右子树
        else if (isLeftChild(pNode)) return pNode->next;
        else
            return [&pNode]() {
                while (pNode->next && !isLeftChild(pNode)) { pNode = pNode->next; }
                return pNode->next;
            }();
    }

private:
    static bool isLeftChild(TreeLinkNode *pNode) {
        return pNode && pNode->next && pNode->next->left == pNode;
    }
};

int main() {
    auto pNode = new TreeLinkNode(8);
    pNode->left = new TreeLinkNode(6);
    pNode->left->next = pNode;
    pNode->right = new TreeLinkNode(10);
    pNode->right->next = pNode;

    pNode->left->left = new TreeLinkNode(5);
    pNode->left->left->next = pNode->left;
    pNode->left->right = new TreeLinkNode(7);
    pNode->left->right->next = pNode->left;

    pNode->right->left = new TreeLinkNode(9);
    pNode->right->left->next = pNode->right;
    pNode->right->right = new TreeLinkNode(11);
    pNode->right->right->next = pNode->right;
    auto res = Solution::GetNext(pNode->left->right);
    cout << (res == nullptr ? "NULL" : to_string(res->val)) << endl;
    return 0;
}
