// 
// Created by tong zeng on 2018/7/24 10:10 AM.
//
#include "commonHeader"

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        if (matrix.empty() || matrix[0].empty()) return result;
        int c1 = 0, c2 = matrix[0].size() - 1; // c means columns
        int r1 = 0, r2 = matrix.size() - 1; // r means rows
        while (c1 <= c2 && r1 <= r2) {
            for (int i = c1; i <= c2; ++i) result.push_back(matrix[r1][i]);
            for (int i = r1 + 1; i <= r2; ++i) result.push_back(matrix[i][c2]);
            if (c1 < c2 && r1 < r2) {
                for (int i = c2 - 1; i >= c1; --i) result.push_back(matrix[r2][i]);
                for (int i = r2 - 1; i > r1; --i ) result.push_back(matrix[i][c1]);
            }
            c1++,c2--,r1++,r2--;
        }
        return result;
    }
private:
    vector<int> result;
};

int main() {
    for(const int n: Solution().printMatrix({{1,2}})){
        cout << n << " ";
    }
    cout << endl;
    return 0;
}