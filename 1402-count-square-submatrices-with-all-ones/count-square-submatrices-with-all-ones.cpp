class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        //create a dp matrix
        vector<vector<int>> dp(n, vector<int>(m, 0));

        //iterate through the matrix to look for 1's.
        int squareCount = 0; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (matrix[i][j] == 0) {
                    continue;
                }

                if (i - 1 < 0 || j - 1 < 0) {
                    dp[i][j] = 1;
                } else if (matrix[i][j] == 1) {
                    dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                }
                
                squareCount += dp[i][j];
            }
        }

        return squareCount;
    }
};

/*

m = [1,0,1],
    [1,1,0],
    [1,1,0]

dp = [1,0,1],
     [1,1,0],
     [1,2,0]

squareCount = 7
*/