// 
// Created by tong zeng on 2018/7/25 3:03 PM.
//

#include "commonHeader"

vector<int> topK(const vector<int> &nums, int k) {
    priority_queue<int> priorityQueue;
    for_each(nums.begin(), nums.end(), [&priorityQueue, k](int n) {
        if (priorityQueue.size() < k) {
            priorityQueue.push(n);
        }
        else if (priorityQueue.top() > n) {
            priorityQueue.pop();
            priorityQueue.push(n);
        }
    });
    vector<int> container;
    while (!priorityQueue.empty()) {
        container.push_back(priorityQueue.top());
        priorityQueue.pop();
    }
    return vector<int>(container.rbegin(), container.rend());
}

int main() {
    vector<int> vec{1,2,3,4,5,3,5,6,4};
    auto res = topK(vec, 4);
    for (const int n: res) cout << n << " ";
    return 0;
}