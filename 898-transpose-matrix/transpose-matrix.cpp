class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();


        vector<vector<int>> res(cols, vector<int>(rows));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res[j][i] = matrix[i][j];
            }
        }

        return res;
    }
};


/*         0 1 2
matrix = [[1,2,3], 0
          [4,5,6], 1
          [7,8,9]] 2

transpose=[[1,4,7],
           [2,5,8],
           [3,6,9]]
*/