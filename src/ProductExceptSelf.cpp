// 
// Created by tong zeng on 2018/7/25 2:04 PM.
//
#include "commonHeader"

class Solution {
public:
    vector<int> multiply(const vector<int>& num) {
        auto size = static_cast<int>(num.size());
        vector<int> ret(size, 1);
        for (int i = 1; i < size; ++i) {
            ret[i] = ret[i - 1] * num[i - 1];
        }
        int latterHalf = 1;
        for (int i = size - 2; i >= 0; --i) {
            latterHalf *= num[i + 1];
            ret[i] *= latterHalf;
        }
        return ret;
    }
};
