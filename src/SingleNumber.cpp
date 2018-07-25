// 
// Created by tong zeng on 2018/7/25 9:52 AM.
//
#include "commonHeader"

/**
 * 1. 按位异或，得到 _xor 的值必然为两个只出现一次的两数的异或值。(相同值异或为0，抵消
 * 2. _xor 二进制位上必然至少存在1位的值为1，找到这一位。
 * 3. 根据第二步找到的位，将 nums 划分为两组，一组该为为0，一组为1。 所要求的两个数分别存在于两个子数组中。
 */
class Solution {
public:
    vector<int> singleNumber(vector<int> &nums) {
        if (nums.empty()) return {};
        int _xor = nums[0];
        for_each(nums.begin() + 1, nums.end(), [&_xor](int n) {
            _xor ^= n;
        });
        int bid = [_xor]() {
            int _bid = 1;
            while (!(_xor & _bid))
                _bid <<= 1;
            return _bid;
        }();

        int num1 = nums[0];
        int cond = nums[0] & bid;
        for_each(nums.begin() + 1, nums.end(), [&num1, bid, cond](int n) {
            if (cond == (n & bid)) num1 ^= n;
        });
        int num2 = _xor ^ num1;
        return {num1, num2};
    }
};
int main() {
    vector<int> vec {1,2,1,3,2,5};
    for (const int n: Solution().singleNumber(vec))
        cout << n << " ";
    return 0;
}