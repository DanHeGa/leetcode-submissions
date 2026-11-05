class Solution {
private:
    vector<vector<char>> grid;
public:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (grid[i][j] == '0') {
            return;
        }

        grid[i][j] = '0';
        vector<int> pairWise = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int newI = i + pairWise[k];
            int newJ = j + pairWise[k + 1];

            if (newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() && grid[newI][newJ] == '1') {
                dfs(newI, newJ, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); 
        int m = grid[0].size();

        int islands = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    islands++;
                }
            }
        }

        return islands;
    }
};