// 
// Created by tong zeng on 2018/7/24 1:02 PM.
//
#include "commonHeader"
// 剑指 offer 为求最小数字
// LeetCode 求最大，只需修改 comparator 即可
class Solution {
public:
    string PrintMinNumber(vector<int> numbers) {
        sort(numbers.begin(), numbers.end(), comparator);
        string res;
        for_each(numbers.begin(), numbers.end(), [&res](int n){ res += to_string(n);});
        return res;
    }
private:
    static bool comparator(int n1, int n2) {
        string m1 = to_string(n1) + to_string(n2);
        string m2 = to_string(n2) + to_string(n1);
        return stoi(m1) < stoi(m2);
    }
};

int main() {
    cout << Solution().PrintMinNumber({3, 32, 321});
    return 0;
}