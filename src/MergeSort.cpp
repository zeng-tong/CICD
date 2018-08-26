// 
// Created by zengtong on 2018/8/25 1:38 PM.
//
#include <vector>
#include <iostream>

using namespace std;

void Merge(vector<int> &nums, int left, int mid, int right) {
    vector<int> aux(right - left + 1);
    for (int i = left; i <= right; ++i) aux[i - left] = nums[i];
    int pre = left, latter = mid;
    for (int i = left; i <= right; ++i) {
        if (pre >= mid) {
            nums[i] = aux[latter - left];
            ++latter;
        } else if (latter > right) {
            nums[i] = aux[pre - left];
            ++pre;
        } else {
            nums[i] = aux[pre - left] < aux[latter - left] ? aux[pre++ - left] : aux[latter++ - left];
        }
    }
}

void MergeSort(vector<int> &nums, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    MergeSort(nums, left, mid);
    MergeSort(nums, mid + 1, right);
    Merge(nums, left, mid, right);
}

int main() {
    vector<int> input{1, 4, 5, 2, 7, 3, 9};
    MergeSort(input, 0, input.size() - 1);
    for(auto e: input) cout << e << " ";
    return 0;
}