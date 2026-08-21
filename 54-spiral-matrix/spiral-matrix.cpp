class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int count = 1;
        int rows = matrix.size();
        int cols = matrix[0].size();
        int number_of_elements = rows * cols;

        vector<int> pairWise = {0, 1, 0, -1, 0}; //starting by going to the right
        vector<vector<int>> visited(rows, vector<int>(cols, false));
        vector<int> ans;
        int i = 0;
        int j = 0;
        int k = 0;
        while(count <= number_of_elements) {
            ans.push_back(matrix[i][j]);
            visited[i][j] = true;

            int newRow = i + pairWise[k];
            int newCol = j + pairWise[k + 1];

            if (newRow < 0 || newRow >= rows || newCol < 0 || newCol >= cols || visited[newRow][newCol]) {
                k = (k + 1) % 4;
            }
            
            i += pairWise[k];
            j += pairWise[k + 1];
            count++;
        }

        return ans;
    }
};