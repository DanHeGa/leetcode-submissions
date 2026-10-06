class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        unordered_map<int, int> changes;
        int maxDate = 0;
        for (auto trip : trips) {
            int passengers = trip[0];
            int start = trip[1];
            int end = trip[2];

            changes[start] += passengers;
            changes[end] -= passengers;
            maxDate = max(maxDate, end);
        }

        int prefixSum = 0;
        for (int i = 0; i <= maxDate; i++) {
            if (changes.contains(i)) {
                prefixSum += changes[i];
               
                if (prefixSum > capacity) {
                    return false;
                }
            }

        }

        return true;
    }
};

/*
trips = [[2,1,5],[3,3,7]] capacity = 4

maxVal = 7
changes = {
    1 : 2,
    5 : -2, 
    3 : 3, 
    7 : 3
}

1 2 3 4 5 6 7 


for range maxVal //latest location
run prefix sum considering changes
*/