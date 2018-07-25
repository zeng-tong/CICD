// 
// Created by tong zeng on 2018/7/24 1:34 PM.
//
#include "commonHeader"


class Solution {
public:
    int getNumberOfK(vector<int> data, int k) {
        if (data.empty()) return 0;
        auto left = lower_bound(data.begin(), data.end(), k);
        auto right = upper_bound(data.begin(), data.end(), k);
        return right - left;
    }
};

int main() {
    cout << Solution().getNumberOfK({1, 2, 3, 3, 3, 3, 4, 5}, 6);
    return 0;
}