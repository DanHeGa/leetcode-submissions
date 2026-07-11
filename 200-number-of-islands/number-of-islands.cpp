class Solution {
public:
    int rows;
    int cols;

    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (grid[i][j] != '1') {
            return;
        }

        grid[i][j] = '0';
        vector<int> pairWise = {-1, 0, 1, 0, -1};
        for (int k = 0; k < 4; k++) {
            int newRow = i + pairWise[k];
            int newCol = j + pairWise[k + 1];
            if (newRow < rows && newRow >= 0 && newCol < cols && newCol >= 0 && grid[newRow][newCol] == '1') {
                dfs(newRow, newCol, grid);
            }
        };
    }

    int numIslands(vector<vector<char>>& grid) {
        rows = grid.size();
        cols = grid[0].size();

        int numIslands = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == '1') {
                    dfs(i, j, grid);
                    numIslands++;
                }
            }
        }

        return numIslands;
    }
};