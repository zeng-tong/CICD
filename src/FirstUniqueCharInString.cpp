// 
// Created by tong zeng on 2018/7/5 10:35 AM.
//
#include "commonHeader"

class Solution {
public:
    //Insert one char from stringstream
    Solution() {
        memset(count, 0, sizeof(count));
    }
    void Insert(char ch) {
        ++count[ch];
        charStream.push_back(ch);
    }
    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {
        for (auto ch: charStream) {
            if (count[ch] == 1) return ch;
        }
        return '#';
    }
private:
    string charStream;
    int count[256];
};

int main() {
    string line;
    while (getline(cin, line)) {
        Solution solution;
        istringstream is(line);
        string input, _require;
        getline(is, input, ',');
        getline(is, _require);
        char require = _require[0];
        for (auto c:input) {
            solution.Insert(c);
        }
//        cout << "res: " << solution.FirstAppearingOnce() <<  " require: " + require << endl;
        assert(solution.FirstAppearingOnce() == require);
    }

    return 0;
}