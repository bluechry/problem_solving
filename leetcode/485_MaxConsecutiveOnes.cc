// Problem ID: Max Consecutive Ones
//
// 문제 설명
//

// 풀이 방법
//
// 시간 복잡도
//
// 공간 복잡도
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
