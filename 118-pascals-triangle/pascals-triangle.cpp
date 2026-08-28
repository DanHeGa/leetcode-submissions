class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;

        for (int i = 0; i < numRows; i++) {
            vector<int> subVec(i + 1, 1);
            triangle.push_back(subVec);
            //[1,2,1], start = 1, max = 1
            if (i > 0) {
                for (int j = 1; j < subVec.size() - 1; j++) {
                    triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
                }
            }
        }

        return triangle;
    }
};