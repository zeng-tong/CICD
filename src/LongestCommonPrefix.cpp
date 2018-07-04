//
// Created by tong zeng on 2018/6/24.
//
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int size = min_element(strs.begin(), strs.end(),
                               [](const string str1,const string str2){
                                   return str1.size() < str2.size();
                               })->size();
        string res = "";
        for (int i = 0; i < size; ++i) {
            char current = strs[0][i];
            for(int j = 0; j < strs.size(); j++) {
                char t = strs[j][i];
                if (current != t) return res;
            }
            res.push_back(current);
        }
        return res;
    }
};

int main() {
    vector<string> strs = {"flower","flow","flight"};
    vector<string> str2 = {""};
    Solution solution;
    cout << solution.longestCommonPrefix(str2) << endl;
}