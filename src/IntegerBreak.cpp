// 
// Created by zengtong on 2018/9/2 11:02 AM.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int integerBreak(int n) {
        if ( n == 1 ) return 1;
        if (memo[n] != -1) return memo[n];
        int _max = INT_MIN;
        for (int i = 1; i <= n - 1; ++i) {
            _max = max3(_max, i * (n - i), i * integerBreak(n - i));// i * (n-i) 不再继续分割的值， i * integerBreak(n - i) 继续分割的值
        }
        memo[n] = _max;
        return _max;
    }
    Solution() : memo(vector<int>(MAX_SIZE, -1)){

    }
private:
    const static int MAX_SIZE = 58 + 1;
    vector<int> memo;
private:
    int max3(int a, int b, int c) {
        return max(max(a, b), c);
    }
};

int main() {
    cout << Solution().integerBreak(58) << endl;
    return 0;
}