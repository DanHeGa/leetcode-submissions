class Solution {
public:
    void checkRottens(queue<pair<int, int>> rottens) {
        while(!rottens.empty()) {
            pair<int, int> thing = rottens.front();
            rottens.pop();
            cout << "( " << thing.first << " , " << thing.second << " ), ";
        }
        cout << endl;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> rottens;
        int freshOnes = 0;
        
        int rows = grid.size();
        int cols = grid[0].size();

        //save all rottens in a queue as first minute rotten ones
        for(int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    pair<int, int> rotCoor = make_pair(i, j);
                    rottens.push(rotCoor);
                } else if (grid[i][j] == 1) {
                    freshOnes++;
                }
            }
        }


        int minutes = 0;
        while(!rottens.empty()) {
            int qSize = rottens.size();
            // cout << "queue size " << qSize << endl;
            cout << "minutes: " << minutes << endl;
            checkRottens(rottens);

            bool smthRot = false;
            for(int i = 0; i < qSize; i++) {
                pair<int, int> currCoor = rottens.front();
                rottens.pop();
                int row = currCoor.first; //x
                int col = currCoor.second; //y

                vector<int> pairWise = {-1, 0, 1, 0, -1};
                for(int k = 0; k < 4; k++) {
                    int newRow = row + pairWise[k];
                    int newCol = col + pairWise[k + 1];

                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                        pair<int, int> newRot = make_pair(newRow, newCol);
                        grid[newRow][newCol] = 2;
                        rottens.push(newRot);
                        freshOnes--;
                        smthRot = true;
                    }
                }
            }

            if (smthRot) {
                minutes++;
            }
        }

        return freshOnes > 0 ? -1 : minutes;

    }
};