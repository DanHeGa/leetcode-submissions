class Solution {
public:
    bool dfs(int currIdx, int currSum, int targetSum, vector<int>& nums, vector<vector<int>> &memo) {
        if (currIdx == nums.size() || currSum > targetSum) {
            return false;
        }

        if (currSum == targetSum) {
            return true;
        }

        if (memo[currIdx][currSum] != -1) {
            return memo[currIdx][currSum];
        }

        bool consider = dfs(currIdx + 1, currSum + nums[currIdx], targetSum, nums, memo);
        bool notConsider = dfs(currIdx + 1, currSum, targetSum, nums, memo);

        memo[currIdx][currSum] = consider || notConsider ? 1 : 0;
        return consider || notConsider ? 1 : 0;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int ele : nums) {
            totalSum += ele;
        }

        if (totalSum % 2 != 0) {
            return false; //not valid patition can be done
        }

        int half = totalSum / 2;
        
        int n = nums.size();
        vector<vector<int>> memo(n + 1, vector<int>(half + 1, -1));
        return dfs(0, 0, half, nums, memo);
    }
};