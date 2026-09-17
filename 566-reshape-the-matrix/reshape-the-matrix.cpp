class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size();
        int cols = mat[0].size();

        //check if it's viable to put input mat elements in r * c matrix
        if (rows * cols != r * c) return mat; //both should have the same capacity

        int row = 0;
        int col = 0;
        vector<vector<int>> res(r, vector<int>(c));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                res[row][col] = mat[i][j];
                col++;

                if (col == c) {
                    col = 0;
                    row++;
                } 
            }
        }

        return res;
    }
};