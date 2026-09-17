class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        unordered_map<int, vector<int>> diagonals;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int currEle = mat[i][j];
                diagonals[i + j].push_back(currEle);
            }
        }

        //add to res vector
        //if odd index sum, reverse the vector AND THEN, push it to the result
        int numDiags = n + m - 1;
        vector<int> res(n * m);
        int resIdx = 0;
        for (int i = 0; i < numDiags; i++) {
            vector<int> currVec = diagonals[i];
            if (i % 2 == 0) {
                reverse(currVec.begin(), currVec.end());
            }

            for (int ele : currVec) {
                res[resIdx] = ele;
                resIdx++;
            }
        }

        return res;
    }
};