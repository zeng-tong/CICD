//
// Created by tong zeng on 2018/7/1.
//
#include "TreeNode"

class Solution {
public:
    static TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (pRoot == nullptr || k <= 0) return nullptr;
        TreeNode* result = nullptr;
        int order = 0;
        traverInorder(pRoot, order, k, result);
        return result;
    }
private:
    static void traverInorder(TreeNode* ptr, int& order, int target, TreeNode* &result){
        if (ptr == nullptr)
            return;
        traverInorder(ptr->left, order, target,result);
        ++order;
        if (order == target) {
            result = ptr;
            return;
        }
        traverInorder(ptr->right, order, target,result);
    }
};

int main() {
    string line;
    while(getline(cin, line)) {
        auto pRoot = readTree(line);
        cout << Solution::KthNode(pRoot, 10)->val << endl;
    }
    return 0;
}

