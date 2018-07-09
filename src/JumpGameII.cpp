// 
// Created by tong zeng on 2018/7/9 9:03 AM.
//
#include "commonHeader"

class Solution {
public:
    int jump(vector<int> &nums) {
        if (nums.size() < 2) return 0;
        return bfs(0, nums);
    }

private:
    int bfs(int pos, vector<int> &nums) {
        vector<bool> visited(nums.size(), false);
        queue<Node> que;
        que.push(createNode(pos, 0));
        while (!que.empty()) {
            auto current = que.front();
            que.pop();
            for (int step = nums[current.index];step >= 1; --step) {
                if (step + current.index >= nums.size() - 1) return current.step + 1;
                else if (!visited[step + current.index]) que.push(createNode(step + current.index, current.step + 1));
                visited[step + current.index] = true;
            }
        }
        return 0;
    }

    struct Node {
        int index;
        int step;
    };

    Node createNode(int i, int s) {
        Node node{.index = i, .step = s};
        return node;
    }
};

int main() {
    Solution solution;
//    vector<int> nums = {8,2,4,4,4,9,5,2,5,8,
//                        8,0,8,6,9,1,1,6,3,5,
//                        1,2,6,6,0,4,8,6,0,3,
//                        2,8,7,6,5,1,7,0,3,4,
//                        8,3,5,9,0,4,0,1,0,5,
//                        9,2,0,7,0,2,1,0,8,2,
//                        5,1,2,3,9,7,4,7,0,0,
//                        1,8,5,6,7,5,1,9,9,3,
//                        5,0,7,5};
//    vector<int> nums(25000, 1);
    vector<int> nums;
    for(int i = 25000; i >= 0; --i) { if (i == 1) nums.push_back(1);
        nums.push_back(i);
    }
    cout << solution.jump(nums) << endl;
    return 0;
}