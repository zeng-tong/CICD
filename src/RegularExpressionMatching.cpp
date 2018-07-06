// 
// Created by tong zeng on 2018/7/6 2:20 PM.
//
#include "commonHeader"

/*
 * 若第二位不是*： 判断第一位是否匹配，如匹配则继续向下匹配否则返回 false
 * 若第二位是*：
 *  分两种情况讨论：
 *      1. 第一位不匹配，那么模式串往后移两位，相当于忽略 x*
 *      2. 第一位匹配，这时候可以有两种方式 isMatch(text, pattern.substr(2)) || isMatch(text.substr(1), pattern);
*/
class Solution {
public:
    bool match(char *_str, char *_pattern) {
        if (_pattern == nullptr) return _str == nullptr;
        string text = stringConverter(_str);
        string pattern = stringConverter(_pattern);
        return isMatch(text, pattern);
    }

private:
    bool isMatch(string text, string pattern) {
        if (pattern.empty()) return text.empty();
        bool first_match = (!text.empty()) && (text[0] == pattern[0] || pattern[0] == '.');
        if (pattern.size() >= 2 && pattern[1] == '*') {
            if (first_match) {
                return isMatch(text, pattern.substr(2)) || isMatch(text.substr(1), pattern);
            } else {
                return isMatch(text, pattern.substr(2));
            }
        } else {
            return first_match && isMatch(text.substr(1), pattern.substr(1));
        }
    }

    string stringConverter(char *ptr) {
        return string(ptr, [&ptr]() {
            while (*ptr != '\0') ++ptr;
            return ptr;
        }());
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        istringstream is(line);
        string _text, _pattern;
        getline(is, _text, ',');
        getline(is, _pattern);
        Solution solution;
        auto text = const_cast<char *>(_text.c_str());
        auto pattern = const_cast<char *>(_pattern.c_str());
        cout << solution.match(text, pattern) << endl;
    }
    return 0;
}