class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int INF = amount + 1;
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, INF));

        dp[0][0] = 0; //0 coind for 0 target amount

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                dp[i][j] = dp[i - 1][j]; //consider not using the current coin before min comparison

                if (j >= coins[i - 1]) {
                    int currCoin = coins[i - 1];
                    dp[i][j] = min(dp[i][j], dp[i][j - currCoin] + 1);
                }
            }
        }

        return dp[n][amount] > amount ? -1 : dp[n][amount];
    }
};