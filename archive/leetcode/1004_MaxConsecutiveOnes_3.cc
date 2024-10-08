// Problem ID: Max Consecutive Ones III
//
// Problem Definition
//   Given a binary array nums and an integer k, return the maximum number of
//   consecutive 1's in the array if you can flip at most k 0's.

// 문제 풀이 #1
//
// 시간 복잡도
//
// 공간 복잡도
//
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int max_ones = 0;
        for (int head = 0; head < nums.size(); ++head) {
            int num_zeros = 0;
            for (int tail = head; tail < nums.size(); ++tail) {
                if (nums[tail] == 0) ++num_zeros;
                if (num_zeros > k) break;
                max_ones = max(max_ones, tail - head + 1);
            }
        }
        return max_ones;
    }
};

// 문제 풀이 #2
//
// 시간 복잡도
//
// 공간 복잡도
//
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int head = 0, num_zeros = 0, max_ones = 0;
        for (int tail = 0; tail < nums.size(); ++tail) {
           if (nums[tail] == 0) {
                if (num_zeros < k) ++num_zeros;
                else while (nums[head++]);
            }
            max_ones = max(max_ones, tail - head + 1);
        }
        return max_ones;
    }
};

// 문제 풀이 #3
//
// 시간 복잡도
//
// 공간 복잡도
//
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int head = 0, num_zeros = 0, max_ones = 0;
        queue<int> prev_zeros;
        for (int tail = 0; tail < nums.size(); ++tail) {
           if (nums[tail] == 0) {
                if (prev_zeros.size() < k) prev_zeros.push(tail);
                else {
                    prev_zeros.push(tail);
                    head = prev_zeros.front() + 1;
                    prev_zeros.pop();
                }
            }
            max_ones = max(max_ones, tail - head + 1);
        }
        return max_ones;
    }
};
