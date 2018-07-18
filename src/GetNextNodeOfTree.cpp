// 
// Created by tong zeng on 2018/7/18 9:01 AM.
//
#include "commonHeader"

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;

    explicit TreeLinkNode(int x) :val(x), left(nullptr), right(nullptr), next(nullptr) {

    }
};
class Solution {
public:
    static TreeLinkNode* GetNext(TreeLinkNode* node) {
        if (node == nullptr)
            return node;
        if (node->right) {
            auto current = node->right;
            while (current->left) current = current->left;
            return current;
        } else if (isLeft(node)) {
            return node->next;
        } else {
            auto current = node;
            while(current && !isLeft(current)) current = current->next;
            return current == nullptr ? nullptr : current->next;
        }
    }
    static TreeLinkNode *readTree(const string &input, int getWhich = 0) {
        TreeLinkNode *res = nullptr;
        TreeLinkNode* which = nullptr;
        int count = 0;
        if (input.empty())
            return res;
        istringstream is(input);

        string val;
        queue<TreeLinkNode *> q;
        getline(is, val, ',');
        res = new TreeLinkNode(stoi(val));
        q.push(res);

        while (getline(is, val, ',')) {
            auto root = q.front(); q.pop();
            if (val != "null") {
                ++count;
                auto left = new TreeLinkNode(stoi(val));
                root->left = left;
                left->next = root;
                q.push(left);
            }
            if (count == getWhich) {
                which = root;
            }
            if (getline(is, val, ',') && val != "null") {
                ++count;
                auto right = new TreeLinkNode(stoi(val));
                root->right = right;
                right->next = root;
                q.push(right);
            }
            if (count == getWhich) {
                which = root;
            }
        }
        return which == nullptr ? res : which;
    }
private:
    static inline bool isLeft(TreeLinkNode* node) {
        return node && node->next && node->next->left == node;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        auto root = Solution::readTree(line, 5);
        cout << Solution::GetNext(root)->val << endl;
    }
    return 0;
}