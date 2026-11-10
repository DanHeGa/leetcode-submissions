class Solution {
public:
    vector<int> bestCoordinate(vector<vector<int>>& towers, int radius) {
        //For each coordinate, we need to calculate distances to all towers and sum up the signal qualities
        int n = 50;
        int bestCoorQuality = 0; 
        vector<int> bestCoor(2);
        for (int i = 0; i <= 50; i++) {
            for (int j = 0; j <= 50; j++) {
                pair<int, int> currCoor = make_pair(i, j); 
                int coorQuality = 0;
                for(auto tower : towers) {
                    //calculate distance to all towers
                    int tx = tower[0];
                    int ty = tower[1];
                    int tQuality = tower[2];
                    int dist = ((tx - currCoor.first) * (tx - currCoor.first)) + ((ty - currCoor.second) * (ty - currCoor.second));
                    
                    if (dist <= radius * radius) {
                        coorQuality += tQuality / (1 + sqrt(dist));
                    }
                }

                if (coorQuality > bestCoorQuality) {
                    bestCoorQuality = coorQuality;
                    bestCoor = {currCoor.first, currCoor.second};
                }
            }
        }

        return bestCoor;
    }
};