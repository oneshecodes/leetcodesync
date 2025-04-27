class Solution {
public:
    int memo(int i, int end, vector<int>& nums, vector<int>& dp) {
        if (i > end) return 0;
        if (dp[i] != -1) return dp[i];
        int pick = nums[i] + memo(i + 2, end, nums, dp);
        int dont = memo(i + 1, end, nums, dp);
        return dp[i] = max(pick, dont);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> dp(n, -1);
        int one = memo(0, n - 2, nums, dp);
        fill(dp.begin(), dp.end(), -1);
        int two = memo(1, n - 1, nums, dp);
        return max(one, two);
    }
};