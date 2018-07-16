// 
// Created by tong zeng on 2018/7/16 8:29 PM.
//

#include "TreeNode"


class Solution {
public:
    vector<vector<int> > FindPath(TreeNode *root, int expectNumber) {
        if (root == nullptr)
            return result;
        findPath(root, expectNumber, vector<int>());
        return result;
    }

private:
    void findPath(TreeNode *root, int sum, vector<int> path) {
        if (root == nullptr) return;
        path.push_back(root->val);
        if (isLeafNode(root) && sum - root->val == 0) {
            result.push_back(path);
            return;
        }
        findPath(root->left, sum - root->val, path);
        findPath(root->right, sum - root->val, path);
    }

private:
    vector<vector<int>> result;

    bool isLeafNode(TreeNode *root) {
        return root && !root->left && !root->right;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        auto root = readTree(line);
        Solution solution;
        auto res = solution.FindPath(root, 22);
        for (auto vec: res) {
            for (auto e: vec)
                cout << e << " ";
            cout << endl;
        }

    }

    return 0;
}