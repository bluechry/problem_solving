// Problem ID: 485. Max Consecutive Ones
//
// Description
//   Given a binary array nums, return the maximum number of consecutive 1's
//   in the array.
//
// Constraints
//   * 1 <= nums.length <= 10^5
//   * nums[i] is either 0 or 1.

// 풀이 방법 #1
//   nums를 0부터 nums.size() - 1까지 스캔하면서 1의 개수를 counting하는데,
//   도중에 0을 만나면 0부터 다시 counting한다.
//   Counting하면서 가장 긴 연속한 1의 개수를 업데이트한다.
//
// 시간 복잡도
//   nums 배열을 처음부터 끝까지 스캔하므로,
//   T(N) = O(N), N = # of elements in nums
//
// 공간 복잡도
//   nums 배열 외에 몇 개의 변수만 필요하므로,
//   S(N) = O(1)
//
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int num_ones = 0, max_ones = 0;
        for (int pos = 0; pos < nums.size(); ++pos) {
            if (nums[pos] == 1) ++num_ones;
            else num_ones = 0;
            max_ones = max(num_ones, max_ones);
        }
        return max_ones;
    }
};
