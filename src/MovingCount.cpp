// 
// Created by tong zeng on 2018/7/6 8:38 AM.
//
#include "commonHeader"

class Solution {
public:
    Solution() : result(0) {}

    int movingCount(int threshold, int rows, int cols) {
        if (rows < 0 || cols < 0) return 0;
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        moving(threshold, rows, cols, 0, 0);
        return result;
    }

private:
    int result;
    vector<vector<bool>> visited;

    void moving(int threshold, int rows, int cols, int i, int j) {
        if (!validPosition(i, j, rows, cols))
            return;
        visited[i][j] = true;
//        printf("[%d][%d] validate, result = %d | ", i, j, result);
        if (getSum(i, j) <= threshold) ++result;
        else return;
//        printf("[%d][%d] validate, after add result = %d\n", i, j, result);
        moving(threshold, rows, cols, i + 1, j);
        moving(threshold, rows, cols, i - 1, j);
        moving(threshold, rows, cols, i, j + 1);
        moving(threshold, rows, cols, i, j - 1);
    }

    bool validPosition(int row, int col, int rows, int cols) {
        return row < rows && col < cols && row >= 0 && col >= 0 && !visited[row][col];
    }

    int getSum(int row, int col) {
        int res = 0;
        while (row) {
            res += row % 10;
            row /= 10;
        }
        while (col) {
            res += col % 10;
            col /= 10;
        }
        return res;
    }
};

int main() {
    Solution solution;
    cout << solution.movingCount(10, 1, 100) << endl; // require 29
    return 0;
}