class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int totalElements = n * n;
        vector<vector<int>> matrix(n, vector<int>(n, -1));

        vector<int> pairWise = {0, 1, 0, -1, 0};
        int count = 0; 

        int i = 0; // i and j are to move through the matrix
        int j = 0;
        int k = 0; //k is to move though pairWise 
        while(count < totalElements) {
            matrix[i][j] = count + 1;
            
            int newRow = i + pairWise[k];
            int newCol = j + pairWise[k + 1];
            //check limits and availability to keep changing elements in matrix
            if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n || matrix[newRow][newCol] != -1) {
                k = (k + 1) % 4;
            }

            //update i and j
            i = i + pairWise[k];
            j = j + pairWise[k + 1];
            count++;
        }

        return matrix;
    }
};