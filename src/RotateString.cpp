// 
// Created by tong zeng on 2018/7/20 10:00 AM.
//
#include "commonHeader"

class Solution {
public:
    static string LeftRotateString(string str, int n) {
        if (str.empty())
            return str;
        n = static_cast<int>(n % str.size());
        if (n == 0) return str;
        auto left = reverse(str.substr(0, n));
        auto right = reverse(str.substr(n));
        return reverse(left + right);
    }

    static string reverse(string str) {
        return string(str.rbegin(), str.rend());
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int n;
        cin >> n;
        cout << Solution::LeftRotateString(line, n) << endl;
    }
    return 0;
}
