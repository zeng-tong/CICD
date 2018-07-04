// 
// Created by tong zeng on 2018/7/1 10:05 PM.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool hasPath(char *_matrix, int rows, int cols, char *str) {
        auto matrix = initMatrix(_matrix, rows, cols);
        for (auto line : matrix) {
            for (auto e: line) cout << e << " ";
            cout << endl;
        }
        if (matrix.empty()) return false;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (findPath(matrix, i, j, 0, str)) return true;
            }
        }
        return false;
    }

private:
    vector<vector<char> > initMatrix(char *matrix, int rows, int cols) {
        vector<vector<char>> res;
        for (int i = 0; i < rows; ++i) {
            res.emplace_back(vector<char>(cols));
            for (int j = 0; j < cols; ++j) {
                res[i][j] = matrix[i * cols + j];
            }
        }
        return res;
    }

    bool findPath(vector<vector<char> > matrix, int row, int col, int begin, char *str) {
        if (str[begin] == '\0') return true;
        if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size()) return false;
        if (matrix[row][col] != str[begin]) return false;
        matrix[row][col] = '\0';
        return findPath(matrix, row - 1, col, begin + 1, str) ||
               findPath(matrix, row + 1, col, begin + 1, str) ||
               findPath(matrix, row, col - 1, begin + 1, str) ||
               findPath(matrix, row, col + 1, begin + 1, str);
    }
};

int main() {


    Solution s;
    char str[] = "abcesfcsadee";
//    cout << s.hasPath(str, 3, 4, "bcced") << endl;
    cout << s.hasPath("ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS", 5, 8, "SGGFIECVAASABCEHJIGQEM") << endl;
    return 0;
}