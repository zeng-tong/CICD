// 
// Created by tong zeng on 2018/7/23 10:25 PM.
//
#include "commonHeader"


class Solution {
public:
    void reOrderArray(vector<int> &num) {
        if (num.empty()) return;
        vector<int> odd;
        vector<int> event;
        for_each(num.begin(), num.end(), [&odd, &event](int n){ n % 2 ? odd.push_back(n) : event.push_back(n);});
        num.assign(odd.begin(), odd.end());
        for_each(event.begin(), event.end(), [&num](int n) {num.push_back(n);});
    }
};

int main() {
    vector<int> num{1,2,3,4,5,6,7};
    Solution().reOrderArray(num);
    return 0;
}