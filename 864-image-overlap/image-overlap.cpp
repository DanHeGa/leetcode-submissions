class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        
        //save img1 1's.
        vector<vector<int>> firstImgOnes;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img1[i][j] == 1) {
                    firstImgOnes.push_back({i, j});
                }
            }
        }
        
        //save img2 1's.
        vector<vector<int>> secondImgOnes;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (img2[i][j] == 1) {
                    secondImgOnes.push_back({i, j});
                }
            }
        }

        //map to save frequency of offset
        int img1Ones = firstImgOnes.size();
        int img2Ones = secondImgOnes.size();
        int maxOffset = 0;
        map<pair<int, int>, int> offsetFreqs;
        for (int i = 0; i < img1Ones; i++) {
            vector<int> currOne = firstImgOnes[i]; //vector like {x, y}
            //get the offset of this one with the other image (img2)
            int currX = currOne[0];
            int currY = currOne[1];
            for (int j = 0; j < img2Ones; j++) {
                vector<int> sndCurrOne = secondImgOnes[j];
                int xOffset = currX - sndCurrOne[0];
                int yOffset = currY - sndCurrOne[1];
                offsetFreqs[{xOffset, yOffset}]++;
                maxOffset = max(maxOffset, offsetFreqs[{xOffset, yOffset}]);
            }
        }

        return maxOffset;
    }
};