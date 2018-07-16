// 
// Created by tong zeng on 2018/7/16 4:59 PM.
//
#include "TreeNode"

class Solution {
public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (t == nullptr || s == nullptr)
            return false;
        bool result = subtree(s, t);
        if (!result) {
            result = isSubtree(s->left, t);
        }
        if (!result) {
            result = isSubtree(s->right, t);
        }
        return result;
    }

private:
    bool subtree(TreeNode *s, TreeNode *t) {
        if (t == nullptr)
            return true;
        if (s == nullptr)
            return false;
        return s->val == t->val &&
               subtree(s->left, t->left) &&
               subtree(s->right, t->right);
    }
};


