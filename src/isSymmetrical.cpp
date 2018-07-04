//
// Created by tong zeng on 2018/7/1.
//
#include "TreeNode"

class Solution {
public:
    static bool isSymmetrical(TreeNode* pRoot) {
        if (pRoot == nullptr) return true;
        return isSym(pRoot->left, pRoot->right);
    }

private:
    static bool isSym(TreeNode* left, TreeNode* right){
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr || left->val != right->val) return false;
        return isSym(left->right, right->left) && isSym(left->left, right->right);
    }
};

int main(){
    string input;
    while(getline(cin, input)) {
        auto treeNode = readTree(input);
        cout << Solution::isSymmetrical(treeNode) << endl;
    }
    return 0;
}