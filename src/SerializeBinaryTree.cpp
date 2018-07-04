// 
// Created by tong zeng on 2018/7/4 9:00 AM.
//

#include <TreeNode>

class Solution {
public:
    static char *Serialize(TreeNode *root) {
        if (root == nullptr)
            return nullptr;
        string* result = new string;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            auto current = que.front();
            que.pop();
            if (current) {
                *result += to_string(current->val) + ",";
                que.push(current->left);
                que.push(current->right);
            } else {
                *result += "null,";
            }
        }
        return const_cast<char *>(result->c_str());
    }

    static TreeNode *Deserialize(char* str) {
        if (str == nullptr || strlen(str) == 0)
            return nullptr;
        TreeNode *res;
        istringstream is(str);
        string val;

        getline(is, val, ',');
        if (val == "null")
            return nullptr;

        res = new TreeNode(stoi(val));
        queue<TreeNode *> que;
        que.push(res);

        while (getline(is, val, ',')) {
            auto current = que.front();
            que.pop();
            if (val != "null") {
                current->left = new TreeNode(stoi(val));
                que.push(current->left);
            }

            if (getline(is, val, ',') && val != "null") {
                current->right = new TreeNode(stoi(val));
                que.push(current->right);
            }
        }
        return res;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
//        auto tree = readTree(line);
//        auto res = Solution::Serialize(tree);
        auto t = Solution::Deserialize(const_cast<char*>(line.c_str()));
        cout << "HELLO" << endl;
//        cout << (res == nullptr ? "null" : res) << endl;
    }
    return 0;
}