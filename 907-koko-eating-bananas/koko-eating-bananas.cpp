class Solution {
public:
    long minEatingSpeed(vector<int>& piles, int h) {
        int maxPileSize = 0;
        for (int i = 0; i < piles.size(); i++) {
            maxPileSize = max(maxPileSize, piles[i]);
        }

        int left = 1;
        int right = maxPileSize;

        int minKval = INT_MAX;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            
            long neededHours = 0;
            for (int pile : piles) {
                if (pile % mid == 0) {
                    neededHours += pile / mid; 
                } else {
                    neededHours += pile / mid + 1;
                }
            }

            if (neededHours <= h) {
                minKval = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return minKval;
    }
};