class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        //get top right elements
        int n = grid.size();
        if (n == 1) return grid;
        
        unordered_map<int, vector<int>> trDiagonals;
        for (int i = 1; i < n; i++) {
            int col = i;
            int row = 0;
            while(row < n && col < n) {
                trDiagonals[i].push_back(grid[row][col]);
                row++;
                col++;
            }
        }

        //get vector diagonals, sort them and put them back in the grid
        for (auto ele : trDiagonals) {
            //order the vector
            int colIdx = ele.first;
            vector<int> currVec = ele.second;
            sort(currVec.begin(), currVec.end(), greater<int>()); //descending
            int row = 0;
            
            while(row < n && colIdx < n && !currVec.empty()) {
                grid[row][colIdx] = currVec.back();
                currVec.pop_back();
                row++;
                colIdx++;
            }
        }

        //get bottom left elements        
        unordered_map<int, vector<int>> blDiagonals;
        for (int j = 0; j < n; j++) {
            int row = j;
            int col = 0;
            while(row < n && col < n) {
                blDiagonals[j].push_back(grid[row][col]);
                row++;
                col++;
            }
        }

        //get vector diagonals, sort them and put them back in the grid
        for (auto ele : blDiagonals) {
            //order the vector
            int rowIdx = ele.first;
            vector<int> currVec = ele.second;

            sort(currVec.begin(), currVec.end()); //ascending, last elements will be the largest
            
            int col = 0;
            while(rowIdx < n && col < n && !currVec.empty()) {
                grid[rowIdx][col] = currVec.back();
                currVec.pop_back();
                rowIdx++;
                col++;
            }
        }

        return grid;
    }
};