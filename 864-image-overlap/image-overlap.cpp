class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<vector<int>> firstImgOnes;
        //save img1 1's.
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) {
                    firstImgOnes.push_back({i, j});
                }
            }
        }

        //map to save frequency of offset
        int img1Ones = firstImgOnes.size();
        int maxOffset = 0;
        map<pair<int, int>, int> offsetFreqs;
        for (int i = 0; i < img1Ones; i++) {
            vector<int> currOne = firstImgOnes[i]; //vector like {x, y}
            //get the offset of this one with the other image (img2)
            int currX = currOne[0];
            int currY = currOne[1];
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (img2[j][k] == 1) {
                        int xOffset = currX - j;
                        int yOffset = currY - k;
                        offsetFreqs[{xOffset, yOffset}]++;
                        maxOffset = max(maxOffset, offsetFreqs[{xOffset, yOffset}]);
                    }
                }
            }
        }

        return maxOffset;
    }
};