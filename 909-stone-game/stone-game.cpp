class Solution {
public:
    int dfs(int i, int j, vector<int>& piles, vector<vector<int>> &memo) {
        if (i >= j) {
            return piles[i];
        }

        if (memo[i][j]) {
            return memo[i][j];
        }

        int left = piles[i] - dfs(i + 1, j, piles, memo);
        int right = piles[j] - dfs(j - 1, i, piles, memo);

        memo[i][j] = max(left, right);
        return max(left, right);
    }

    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> memo(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            memo[i][i] = piles[i];
        }

        return dfs(0, 0, piles, memo);
    }
};

/*
- even number of piles
- odd number of stones in each pile
- no ties
- each turn, take from the beginning or from the end 
- true if Alice wins (always starts first), false if not (Bob won)
*/