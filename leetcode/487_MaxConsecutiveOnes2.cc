// Problem ID: 
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
    int head = 0, num_ones = 0, num_zeros = 0, max_ones = 0;
    for (int tail = 0; tail < nums.size(); ++tail) {
      if (nums[tail] == 1)
        ++num_ones;
      // nums[tail] == 0 and num_zeros == 0
      else if (num_zeros == 0) {
        num_zeros = 1;
        ++num_ones;
      }
      // nums[tail] == 0 and num_zeros == 1
      else {
        while(nums[head++] == 1);
        num_ones = tail - head + 1;
        num_zeros = 1;
      }
      max_ones = max(max_ones, num_ones);
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
    int num_ones = 0, num_zeros = 0, max_ones = 0, pos_zero;
    for (int pos = 0; pos < nums.size(); ++pos) {
      if (nums[pos] == 1)
        ++num_ones;
      // nums[pos] == 0 and num_zeros == 0
      else if (num_zeros == 0) {
        num_zeros = 1;
        ++num_ones;
        pos_zero = pos;
      }
      // nums[pos] == 0 and num_zeros == 1
      else {
        num_ones = pos - pos_zero;
        num_zeros = 1;
        pos_zero = pos;
      }
      max_ones = max(max_ones, num_ones);
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
