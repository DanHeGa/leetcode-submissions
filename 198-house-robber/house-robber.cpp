class Solution {
public:
    int dfs(int i, vector<int>& dp, vector<int> &nums) {
        if (i >= nums.size()) {
            return 0;
        }

        if (dp[i] < 0){
            int maxProfit = max(nums[i] + dfs(i + 2, dp, nums), dfs(i + 1, dp, nums));

            dp[i] = maxProfit;
            return maxProfit;
        }

        return dp[i];
    }

    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return dfs(0, dp, nums);
    }
};