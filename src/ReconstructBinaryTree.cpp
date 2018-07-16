// 
// Created by tong zeng on 2018/7/16 8:44 AM.
//

#include "TreeNode"
#include "commonHeader"

class Solution {
public:
    TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {
        if (pre.size() != vin.size())
            return nullptr;

        return constructBinaryTree(pre, vin, pre.begin(), pre.end(), vin.begin(), vin.end());
    }

private:
    TreeNode *constructBinaryTree(vector<int> &pre, vector<int> &vin,
                                  vector<int>::iterator pre_start, vector<int>::iterator pre_end,
                                  vector<int>::iterator vin_start, vector<int>::iterator vin_end) {
        if (pre_start == pre_end)
            return nullptr;
        auto currentValue = *pre_start;
        auto root = new TreeNode(currentValue);
        auto vin_current = find(vin_start, vin_end, currentValue);

        auto leftOffset = vin_current - vin_start;
        root->left = constructBinaryTree(pre, vin, pre_start + 1, pre_start + leftOffset + 1, vin_start, vin_current);
        root->right = constructBinaryTree(pre, vin, pre_start + leftOffset + 1, pre_end, vin_current + 1, vin_end);
        return root;
    }
};

int main() {
    vector<int> pre = {1, 2, 4, 5, 3, 6, 7};
    vector<int> vin = {4, 2, 5, 1, 6, 3, 7};
    Solution solution;
    auto res = solution.reConstructBinaryTree(pre, vin);
    return 0;
}