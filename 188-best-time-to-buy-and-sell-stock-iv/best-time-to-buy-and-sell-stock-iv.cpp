class Solution {
public:
    int dfs(int currDay, int left, bool holding, vector<int>& prices, vector<vector<vector<int>>> &dp) {
        if (currDay >= prices.size()) {
            return 0;
        }

        int holdIdx = holding ? 1 : 0;
        if (dp[currDay][left][holdIdx] != -1) {
            return dp[currDay][left][holdIdx];
        }

        int ans = dfs(currDay + 1, left, holding, prices, dp);
        if (holding) {
            //if holding, we can only sell
            ans = max(ans, prices[currDay] + dfs(currDay + 1, left, false, prices, dp));
        } else if (!holding && left > 0) {
            //if NOT holding, we can only buy
            ans = max(ans, -prices[currDay] + dfs(currDay + 1, left - 1, true, prices, dp));
        }

        dp[currDay][left][holdIdx] = ans;
        return ans;
    }

    int maxProfit(int k, vector<int>& prices) {
        //track three states, current day, available transactions, holding a stock or not
        //dp for the maxProfit at certain day, with certain number of left transactions, and holding or not
        int n = prices.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        int ans = dfs(0, k, false, prices, dp);
        return ans;
    }
};

/*
k = 2, prices = [2,4,1] size = 3

i = 0, k = 2, hold = false

*/
