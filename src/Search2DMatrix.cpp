// 
// Created by tong zeng on 2018/7/23 9:31 AM.
//
#include "commonHeader"

class Solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;
        auto comparator = [](const vector<int>& current, const int val) { return current.back() < val; };
        auto it = lower_bound(matrix.begin(), matrix.end(), target, comparator);
        if (it == matrix.end())
            return false;
        return binary_search(it->begin(), it->end(), target);
    }
};
int main() {
    vector<vector<int>> vecs{{1,  3,  5,  7},
                             {10, 11, 16, 20},
                             {23, 30, 34, 50}};
    cout << Solution().searchMatrix(vecs, 3) << endl;
    return 0;
}