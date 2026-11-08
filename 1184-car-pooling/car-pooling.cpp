class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int, int> pooling;
        for (auto trip : trips) {
            pooling[trip[1]] += trip[0];
            pooling[trip[2]] -= trip[0];
        }

        int currCarry = 0;
        for (auto pool : pooling) {
            currCarry += pool.second;
            if (currCarry > capacity) return false;
        }

        return true;
    }
};