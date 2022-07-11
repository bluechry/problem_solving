// Problem ID: Max Consecutive Ones II
//
// 문제 설명
//

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

// 풀이 방법 4
//
// 시간 복잡도
//
// 공간 복잡도
//
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur_ones = 0, prev_ones = 0, max_ones = 0, isFlipped = 0;
        for (int pos = 0; pos < nums.size(); ++pos) {
            if (nums[pos] == 1) {
                ++cur_ones;
            } else if (nums[pos] == 0) {
                prev_ones = cur_ones;
                cur_ones = 0;
                isFlipped = 1;
            }
            max_ones = max(max_ones, cur_ones + prev_ones + isFlipped);
        }
        return max_ones;
    }
};
