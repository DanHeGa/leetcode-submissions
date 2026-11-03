class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int freshOnes = 0;
        //count rotten oranges
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

        int minutes = 0;
        vector<int> pairWise = {-1, 0, 1, 0, -1};
        while(!q.empty()) {
            bool sthmgRott = false;
            int qSize = q.size();

            //for each rott orange, check its adjacent FRESH ones and ROTT them
            for (int i = 0; i < qSize; i++) {
                pair<int, int> currRott = q.front();
                q.pop();
                
                for (int k = 0; k < 4; k++) {
                    int newI = currRott.first + pairWise[k];
                    int newJ = currRott.second + pairWise[k + 1];

                    //check limits
                    if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && grid[newI][newJ] == 1) {
                        //mark as rotten (visited), and add to queue
                        q.push({newI, newJ});
                        grid[newI][newJ] = 2;
                        freshOnes--;
                        sthmgRott = true;
                    }
                }
            }

            if (sthmgRott) {
                minutes++;
            }
        }

        return freshOnes == 0 ? minutes : -1;
    }
};