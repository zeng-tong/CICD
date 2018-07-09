// 
// Created by tong zeng on 2018/7/9 7:50 PM.
//

#include "commonHeader"

class Solution {
public:
    static bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        vector<int> res;
        for (int i = 0, j = 0; i < pushV.size(); ++i) {
            res.push_back(pushV[i]);
            while (j < popV.size() && res.back() == popV[j]) {
                res.pop_back();
                ++j;
            }
        }
        return res.empty();
    }
};

int main() {
    cout << Solution::IsPopOrder({1, 2, 3, 4, 5}, {4, 3, 5, 1, 2}) << endl;
    return 0;
}

