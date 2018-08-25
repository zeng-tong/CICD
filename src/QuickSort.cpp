// 
// Created by zengtong on 2018/8/25 12:47 PM.
//

#include <vector>
#include <iostream>

using namespace std;

int Partition(vector<int> &num, int left, int right) {
    int end = right;
    for (int i = left + 1; i <= end; ++i) {
        if (num[i] > num[left]) swap(num[i--], num[end--]);
    }
    swap(num[left], num[end]);
    return end;
}

void quickSort(vector<int> &nums, int left, int right) {
    if (left >= right) return;
    int pivot = Partition(nums, left, right);
    quickSort(nums, left, pivot);
    quickSort(nums, pivot + 1, right);
}

int main() {
    vector<int> res;
    istream_iterator<int> in(cin), eof;
    copy(in, eof, back_inserter(res));
    quickSort(res, 0, res.size() - 1);
    for (auto e: res) cout << e << " ";
    return 0;
}