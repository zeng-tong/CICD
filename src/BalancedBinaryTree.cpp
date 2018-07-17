// 
// Created by tong zeng on 2018/7/17 10:04 AM.
//

#include "TreeNode"

class Solution {
public:
    static bool isBalanced(TreeNode* root) {
        if (root == nullptr)
            return true;
        return abs(depth(root->left) - depth(root->right)) <= 1 &&
               isBalanced(root->left) &&
               isBalanced(root->right);
        /*
        bool balanced = true;
        balanced = (abs(depth(root->left) - depth(root->right)) <= 1);
        if (balanced == false)
            return false;
        balanced = isBalanced(root->left);
        if (balanced == false)
            return false;
        return isBalanced(root->right);
        */
    }

private:
    static int depth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return max(depth(root->right) + 1, depth(root->left) + 1);
    }
};
int main() {
    string line;
    while (getline(cin, line)) {
        auto root = readTree(line);
        cout << Solution::isBalanced(root) << endl;
    }
    return 0;
}

