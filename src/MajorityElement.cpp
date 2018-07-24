// 
// Created by tong zeng on 2018/7/24 11:03 AM.
//
#include "commonHeader"

class Solution {
    // [1,2,3,2,4,2,5,2,3]
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if (numbers.empty())
            return 0;
        int count = 1, candidate = numbers[0];
        for (int i = 1; i < numbers.size(); ++i) {
            if (count == 0) {
                candidate = numbers[i];
            }
            numbers[i] == candidate ? ++count : --count;
        }
        if ( (count == 1 && !MoreThanHalf(numbers, candidate)) || count < 1)
            return 0;
        return candidate;
    }

private:
    bool MoreThanHalf(const vector<int> &numbers, int candidate) {
        return count(numbers.begin(), numbers.end(), candidate) > (numbers.size() / 2);
    }
};

int main() {
    cout << Solution().MoreThanHalfNum_Solution({1,2,2,3,2}) << endl;
    return 0;
}
