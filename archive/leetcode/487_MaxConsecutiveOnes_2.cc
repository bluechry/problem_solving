// Problem ID: 487. Max Consecutive Ones II
//
// Problem Definition
//   Given a binary array nums, return the maximum number of consecutive 1's
//   in the array if you can flip at most one 0.
//
// Constraints
//   * 1 <= nums.length <= 10^5
//   * nums[i] is either 0 or 1.

// 풀이 방법 1
//
// 시간 복잡도
//
// 공간 복잡도
//
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ones = 0;
        for (int head = 0; head < nums.size(); ++head) {
            int num_zeros = 0;
            for (int tail = head; tail < nums.size(); ++tail) {
                if (nums[tail] == 0) ++num_zeros;
                if (num_zeros > 1) break;
                max_ones = max(max_ones, tail - head + 1);
            }
        }
        return max_ones;
    }
};

// 풀이 방법 2
//
// 시간 복잡도
//
// 공간 복잡도
//
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int head = 0, num_zeros = 0, max_ones = 0;
        for (int tail = 0; tail < nums.size(); ++tail) {
            if (nums[tail] == 0) {
                if (num_zeros < 1) ++num_zeros;
                else while (nums[head++]);
            }
            max_ones = max(max_ones, tail - head + 1);
        }
        return max_ones;
    }
};

// 풀이 방법 3
//
// 시간 복잡도
//
// 공간 복잡도
//
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int head = 0, num_zeros = 0, max_ones = 0;
        int zero_pos;
        for (int tail = 0; tail < nums.size(); ++tail) {
            if (nums[tail] == 0) {
                if (num_zeros < 1) {
                    ++num_zeros;
                    zero_pos = tail;
                } else {
                    head = zero_pos + 1;
                    zero_pos = tail;
                }
            }
            max_ones = max(max_ones, tail - head + 1);
        }
        return max_ones;
    }
};
