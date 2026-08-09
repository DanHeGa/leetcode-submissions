class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int mid;
        if (n % 2 == 0) {
            mid = n / 2 - 1;
        } else {
            mid = n / 2;
        }

        //inverse input matrix
        for (int i = 0; i <= mid; i++) {
            swap(matrix[i], matrix[n - i -1]);
        }

        //transpose inverted matrix
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};