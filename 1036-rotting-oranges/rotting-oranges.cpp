class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        //count number of fresh oranges, as well as getting the location of rotten ones
        queue<pair<int, int>> q;
        int freshOnes = 0;
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    freshOnes++;
                } else if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        //pair wise movements to rott adjacent fresh fruits 
        int rotten = 0;
        int minutes = 0;
        vector<int> pairWise = {-1, 0, 1, 0, -1};
        while(!q.empty()) {
            int qSize = q.size();
            bool smthgRott = false; 
            for (int i = 0; i < qSize; i++) {
                pair<int, int> currRott = q.front();
                q.pop();
                
                for (int k = 0; k < 4; k++) {
                    int newRow = currRott.first + pairWise[k];
                    int newCol = currRott.second + pairWise[k + 1];

                    if (newRow < n && newRow >= 0 && newCol < m && newCol >= 0 && grid[newRow][newCol] == 1) {
                        q.push({newRow, newCol});
                        rotten++;
                        grid[newRow][newCol] = 2;
                        smthgRott = true;
                    }
                }
            }
            if (smthgRott) minutes++;
        }

        return rotten == freshOnes ? minutes : -1;
    }
};