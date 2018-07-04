#include "TreeNode"
#include <vector>

//
// Created by tong zeng on 2018/7/1.
//
class Solution {
public:
    vector<vector<int> > Print(TreeNode *pRoot) {
        if (pRoot == nullptr)
            return result;
        deque<Guide> path;
        path.push_front(createGuide(PRINT, 0, pRoot));
        path.push_back(createGuide(VISIT, 1, pRoot->left));
        path.push_back(createGuide(VISIT, 1, pRoot->right));

        vector<int> sameLevelElem;
        int level = 0;
        while (!path.empty()) {
            Guide current = path.front();
            path.pop_front();
            if (current.ptr == nullptr) continue;
            if (current.operation == PRINT) {
                if (!sameLevelElem.empty() && level != current.level) {
                    result.push_back(sameLevelElem);
                    vector<int>().swap(sameLevelElem);
                    sameLevelElem.push_back(current.ptr->val);
                    level = current.level;
                } else {
                    sameLevelElem.push_back(current.ptr->val);
                }
            } else {
                path.push_front(createGuide(PRINT, current.level, current.ptr));
                path.push_back(createGuide(VISIT, current.level + 1, current.ptr->left));
                path.push_back(createGuide(VISIT, current.level + 1, current.ptr->right));
            }
        }
        result.push_back(sameLevelElem);
        return result;
    }

private:
    vector<vector<int> > result;
    const static int PRINT = 0;
    const static int VISIT = 1;
    struct Guide {
        int operation;
        int level;
        TreeNode *ptr;
    };

    static Guide createGuide(int operation, int level, TreeNode *ptr) {
        Guide res = {operation, level, ptr};
        return res;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        auto pRoot = readTree(line);
        Solution solution;
        auto res = solution.Print(pRoot);
        for (auto level: res) {
            for (auto each: level) cout << each << " ";
            cout << endl;
        }
    }

    return 0;
}