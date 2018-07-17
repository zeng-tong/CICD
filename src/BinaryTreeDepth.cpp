// 
// Created by tong zeng on 2018/7/17 9:31 AM.
//

#include "TreeNode"

class Solution {
public:
    static int TreeDepth(TreeNode *root) { // 1. recursive 2. level traverse
        if (root == nullptr)
            return 0;
        return max(TreeDepth(root->left) + 1, TreeDepth(root->right) + 1);
    }
};

int main() {

    string line;
    while (getline(cin, line)) {
        auto root = readTree(line);
        cout << Solution::TreeDepth(root) << endl;
    }
    return 0;
}