//
// Created by tong zeng on 2018/7/1.
//
#include "TreeNode"

class Solution {
public:
    static bool isSymmetrical(TreeNode *root) {
        return root == nullptr || symmetrical(root->left, root->right);
    }

private:
    static bool symmetrical(TreeNode *left, TreeNode *right) {
        if (left == nullptr && right == nullptr)
            return true;
        if (left == nullptr || right == nullptr || left->val != right->val)
            return false;
        return symmetrical(left->left, right->right) && symmetrical(left->right, right->left);
    }
};

int main() {
    string input;
    while (getline(cin, input)) {
        auto treeNode = readTree(input);
        cout << Solution::isSymmetrical(treeNode) << endl;
    }
    return 0;
}