// 
// Created by tong zeng on 2018/7/20 10:39 AM.
//
#include "commonHeader"


class Solution {
public:
    string ReverseSentence(string str) {
        if (str.empty()) return str;
        auto words = split(str, ' ');
        string res;
        for_each(words.rbegin(), words.rend(), [&res](string word){ res += word + " ";});
        return res.substr(0, str.size());
    }
private:
    vector<string> split(const string &str, char separator) {
        if (str.empty())
            return vector<string>();
        vector<string> ret;
        string word;
        istringstream is(str);
        while (getline(is, word, separator)) ret.push_back(word);
        return ret;
    }
};

int main() {
    Solution solution;
    string line;
    while (getline(cin, line)) {
        cout << solution.ReverseSentence(line) << endl;
    }
    return 0;
}