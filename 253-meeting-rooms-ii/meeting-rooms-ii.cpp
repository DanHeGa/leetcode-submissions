class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //get time stamp based room count
        int maxTime = 0;
        for (auto interval : intervals) {
            maxTime = max(maxTime, interval[1]);
        }
        
        vector<int> mp(maxTime + 1);
        for (auto interval : intervals) {
            mp[interval[0]]++;
            mp[interval[1]]--;
        }

        int overlaps = 0;
        int maxOverlaps = 0;
        for (int i = 0; i <= maxTime; i++) {
            overlaps += mp[i];
            maxOverlaps = max(maxOverlaps, overlaps);
        }

        return maxOverlaps;
    }
};