class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //get time stamp based room count
        map<int, int> mp;
        for (auto interval : intervals) {
            mp[interval[0]]++;
            mp[interval[1]]--;
        }

        int overlaps = 0;
        int maxOverlap = 0;
        for (auto time : mp) {
            overlaps += time.second;
            maxOverlap = max(maxOverlap, overlaps);
        }

        return maxOverlap;
    }
};