// 
// Created by tong zeng on 2018/7/19 10:39 AM.
//

#include "commonHeader"

class Permutation{
public:
    vector<string> operator()(const string& str) {
        _permutation(str, 0);
        return ret;
    }

private:
    void _permutation(string str, int pos) {
        if (pos == str.size() - 1) {
            ret.push_back(str);
            return;
        }
        for(int i = pos; i < str.size(); ++ i) {
            swap(str[i], str[pos]);
            _permutation(str, pos + 1);
            swap(str[i], str[pos]);
        }
    }

private:
    vector<string> ret;
};

int main() {
    string line;
    while (getline(cin, line)) {
        auto res = Permutation()(line);
        for(const auto &str: res) cout << str << endl;
    }

    return 0;
}