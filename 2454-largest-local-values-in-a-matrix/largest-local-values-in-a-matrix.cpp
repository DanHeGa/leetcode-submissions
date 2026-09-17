class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> maxVal (n - 2, vector<int>(n - 2));

        for (int i = 0; i < n - 2; i++) {
            for (int j = 0; j < n - 2; j++) {
                int iCenter = i + 1;
                int jCenter = j + 1;

                int maxValGrid = 0;
                for (int iGrid = iCenter - 1; iGrid <= iCenter + 1; iGrid++){
                    for (int jGrid = jCenter - 1; jGrid <= jCenter + 1; jGrid++) {
                        maxValGrid = max(maxValGrid, grid[iGrid][jGrid]);
                    }
                }

                maxVal[i][j] = maxValGrid;
            }
        }

        return maxVal;
    }
};


/*  i =  0 1 2 3 
grid = [[9,9,8,1], 0 
        [5,6,2,6], 1 
        [8,2,6,4], 2
        [6,2,2,2]] 3
       
       i = 0 1 
maxVal = [[9,9], 0
          [8,6]] 1
*/