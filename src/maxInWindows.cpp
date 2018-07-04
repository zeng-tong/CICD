// 
// Created by tong zeng on 2018/7/4 10:51 AM.
//
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    static vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> result;
        if (size == 0) return result;
        auto front = num.begin();
        for(; front + size - 1 != num.end(); ++front) {
            result.push_back(*max_element(front, front + size));
        }
        return result;
    }
};

int main() {

    vector<int> vec = {2,3,4,2,6,2,5,1};
    auto res = Solution::maxInWindows(vec, 3);
    for(auto e:res) cout << e << " ";
    return 0;
}