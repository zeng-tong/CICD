#include <iostream>
#include <string>
#include <vector>

using namespace std;

class KMP {
public:
    KMP() {
    }
    int findSub(const string& source, const string& pattern) {
        generateNext(pattern);
        int sourceLength = source.size(), patternLength = pattern.size();
        int p = 0, s = 0;
        while(p < patternLength && s < sourceLength && patternLength <= sourceLength) {
            if (pattern[p] == source[s])
                ++s, ++p;
            else if (p == 0)
                ++s;
            else 
                p = next[p -1];
        }
        return p == patternLength ? s - patternLength : -1;
    }
private:
    vector<int> next;
    void generateNext(const string& pattern) {
        next = vector<int>(pattern.size(), 0);
        
        int i = 1;
        while(i < pattern.size()) {
            int j = next[i - 1];
            while(j > 0 && pattern[i] != pattern[j]) j = next[j - 1];
            if (pattern[i] == pattern[j])
                next[i] = j + 1;
            else
                next[i] = 0;
            ++i;
        }
    }
};

int main() {
    KMP kmp;
    cout << kmp.findSub("abcddbaaadcdcabdg", "dcdca") << endl;
    return 0;
}