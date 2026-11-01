class Solution {
public:
    void print(vector<vector<int>>& dp) {
        for (int i = 0; i < dp.size(); i++) {
            for (int j = 0; j < dp[0].size(); j++) {
                cout << dp[i][j] << " ";
           }
           cout << endl;
        }
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(); //rows
        int m = matrix[0].size(); //cols

        vector<vector<int>> dp(n, vector<int>(m, 0));
        int maxSide = 0;

        for (int i = 0; i < n; i++) { //rows
            dp[i][0] = matrix[i][0] == '1' ? 1 : 0;
            maxSide = max(maxSide, dp[i][0]);
        }

        for (int i = 0; i < m; i++) { //cols
            dp[0][i] = matrix[0][i] == '1' ? 1 : 0;
            maxSide = max(maxSide, dp[0][i]);
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == '0') continue;

                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j]));
                maxSide = max(maxSide, dp[i][j]); 
            }
        }

        print(dp);
        int maxArea = maxSide * maxSide;
        return maxArea;
    }
};

/*
matrix:
["1","0","1","0","0"],
["1","0","1","1","1"],
["1","1","1","1","1"],
["1","0","0","1","0"]

dp:
[0,0,0,0,0],
[0,0,0,0,0],
[0,0,0,0,0],
[0,0,0,0,0]

*/