// 
// Created by tong zeng on 2018/7/6 5:16 PM.
//
#include "commonHeader"

class Solution {
public:
    static bool isNumeric(char *string) {
        // Nowcoder OJ： https://www.nowcoder.com/questionTerminal/6f8c901d091949a5837e24bb82a731f2
        if (string == nullptr || string[0] == '0') return false;
        if (isSign(string[0])) ++string;

        int dotCount = 0;
        int digCount = 0;
        int eCount = 0;
        while (*string != '\0') {
            if (isDigital(*string)) {
                ++digCount, ++string;
            } else if (*string == '.') {
                if (/*digCount == 0 ||*/ dotCount > 0 || eCount > 0) return false;
                else ++string, ++dotCount;
            } else if (*string == 'E' || *string == 'e') {
                char nextChar = *(string + 1);
                if (eCount > 0 || (!isDigital(nextChar) && !isSign(nextChar))) return false;
                if (isSign(nextChar)) ++string;
                ++string, ++digCount, ++eCount;
            } else {
                return false;
            }
        }
        return true;
    }
private:
    static bool isDigital(char ch) {
        return ch >= '0' && ch <= '9';
    }

    static bool isSign(char ch) {
        return ch == '+' || ch == '-';
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        auto *str = const_cast<char *>(line.c_str());
        cout << Solution::isNumeric(str) << endl;
    }
    return 0;
}