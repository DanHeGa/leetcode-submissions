class NumMatrix {
private:
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        prefix.resize(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i - 1 < 0 && j - 1 < 0) {
                    prefix[i][j] = matrix[i][j];
                } else if (i - 1 < 0 && j - 1 >= 0) {
                    prefix[i][j] = matrix[i][j] + prefix[i][j - 1];
                } else if (j - 1 < 0 && i - 1 >= 0) {
                    prefix[i][j] = matrix[i][j] + prefix[i - 1][j];
                } else {
                    prefix[i][j] = matrix[i][j] + prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total = prefix[row2][col2];
        int upperRight = row1 > 0 ? prefix[row1 - 1][col2] : 0;
        int bottomLeft = col1 > 0 ? prefix[row2][col1 - 1] : 0;
        int leftUpperCorner = (col1 > 0 && row1 > 0) ? prefix[row1 - 1][col1 - 1] : 0;

        return total - upperRight - bottomLeft + leftUpperCorner;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */