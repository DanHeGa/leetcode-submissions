class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<bool> zeroRows(rows, false);
        vector<bool> zeroCols(cols, false);

        //iterate over matrix to find zeros and set boolean vectors where zeros are found
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    zeroRows[i] = true;
                    zeroCols[j] = true;
                }
            }
        }

        //iterate over rows vector to turn those True rows into 0
        for (int i = 0; i < rows; i++) {
            if (zeroRows[i]) {
                for (int k = 0; k < cols; k++) {
                    matrix[i][k] = 0;
                }
            }
        }

        //same with cols
        for (int i = 0; i < cols; i++) {
            if (zeroCols[i]) {
                for (int k = 0; k < rows; k++) {
                    matrix[k][i] = 0;
                }
            }
        }
    }
};