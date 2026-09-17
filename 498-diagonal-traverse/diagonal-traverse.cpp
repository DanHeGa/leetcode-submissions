class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        bool going_up = true;
        int count = 0;
        int totalElements = rows * cols;
        vector<int> res(totalElements);

        int row = 0;
        int col = 0;
        while(count < totalElements) {
            if (going_up) {
                while (row >= 0 && col < cols) {
                    res[count] = mat[row][col];
                    count++;

                    row -= 1;
                    col += 1;
                }

                if (row < 0 && col < cols) { //only the row is not within limits
                    row += 1;
                } else if (col >= cols) {
                    row += 2;
                    col -= 1;
                }

                going_up = false;
            } else { //going down
                while(row < rows && col >= 0) {
                    res[count] = mat[row][col];
                    count++;

                    row += 1;
                    col -= 1;
                }

                if (col < 0 && row < rows) {
                    col += 1;
                } else if (row >= rows) {
                    col += 2;
                    row -= 1;
                }
                
                going_up = true;
            }
        }
        return res;
    }
};