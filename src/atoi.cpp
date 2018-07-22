// 
// Created by tong zeng on 2018/7/22 10:54 AM.
//

#include <cctype>
#include "commonHeader"

enum StatuCode {
    VALID = 0, EXCEED, INVALID
};

// 最大正整数: 0x7FFFFFFF
// 最小负整数: 0x80000000
const static int POSITIVE_INT_MAX=  0x7FFFFFFF;
const static signed int NAGETIVE_INT_MIN = 0x80000000;

int status = INVALID;

int strToIntCore(const char *str, bool isPositive);

int strToInt(const char *str) {
    status = INVALID;
    if (str == nullptr) return 0;
    while (str && *str == ' ') ++str;
    bool positive = true;
    if (*str == '+') {
        ++str;
        positive = true;
    } else if (*str == '-') {
        ++str;
        positive = false;
    }
    int ret = strToIntCore(str, positive);
    return positive ? ret : -ret;
}
int strToIntCore(const char *str, bool isPositive) {
    if (str == nullptr || *str == '\0') return 0;
    int ret = 0;
    while (str && *str != '\0') {
        if (!isdigit(*str)) return 0;
        ret = ret * 10 + (*str - '0');
        if ((isPositive && ret > POSITIVE_INT_MAX) ||
            (!isPositive && ret < NAGETIVE_INT_MIN)) {
            status = EXCEED;
            break;
        }
        ++str;
    }
    if (str && *str == '\0') status = VALID;
    return ret;
}

int main() {
    string line;
    while (getline(cin, line)) {
        auto ret = strToInt(line.c_str());
        if (ret == 0 && status != VALID) {
            if (status == EXCEED) cout << "OUT OF INT RANGE" << endl;
            else cout << "VALID NUMBER" << endl;
        } else {
            cout << ret << endl;
        }
    }

    return 0;
}