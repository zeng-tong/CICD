// 
// Created by tong zeng on 2018/7/18 10:19 AM.
//
#include "TreeNode"
#include "commonHeader"

class Solution {
public:
    vector<vector<int> > Print(TreeNode *root) {
        if (root == nullptr)
            return result;
        que.push(root);
        que.push(nullptr);
        bool isLeftDirection = true;
        while (!que.empty()) {
            auto current = que.front();
            que.pop();
            if (current == nullptr) continue;
            container.push_back(current->val);
            if (current->left) que.push(current->left);
            if (current->right) que.push(current->right);
            if (que.front() == nullptr) {
                result.emplace_back(isLeftDirection ? std::move(container) : vector<int>(container.rbegin(), container.rend()));
                vector<int>().swap(container);
                isLeftDirection = !isLeftDirection;
                que.push(nullptr);
            }
        }
        return result;
    }

private:
    queue<TreeNode *> que;
    vector<vector<int>> result;
    vector<int> container;
};

int main() {
    string line;
    while (getline(cin, line)) {
        Solution solution;
        auto root = readTree(line);
        auto res = solution.Print(root);
        for (auto vec: res) {
            for (auto item: vec) {
                cout << item << " ";
            }
            cout << endl;
        }
    }
    return 0;
}


