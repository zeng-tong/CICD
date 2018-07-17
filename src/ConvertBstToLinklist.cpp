// 
// Created by tong zeng on 2018/7/17 9:06 AM.
//

#include "TreeNode"

class Solution {
public:
    static TreeNode *Convert(TreeNode *pRootOfTree) {
        if (pRootOfTree == nullptr)
            return nullptr;
        TreeNode* lastNode = nullptr;
        convert_tree(pRootOfTree, lastNode);
        auto firstNode = pRootOfTree;
        while (firstNode && firstNode->left) firstNode = firstNode->left;
        return firstNode;
    }

private:
    static void convert_tree(TreeNode *root, TreeNode *&lastNode) {
        if (root == nullptr)
            return;

        convert_tree(root->left, lastNode);

        root->left = lastNode;
        if (lastNode) lastNode->right = root;
        lastNode = root;

        convert_tree(root->right, lastNode);
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        auto root = readTree(line);
        auto res = Solution::Convert(root);
        while(res) {
            cout << res->val;
            if (res->right) cout << "->";
            res = res->right;
        }
    }
    return 0;
}