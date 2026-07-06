class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return true;
        }
        
        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (prevEnd > intervals[i][0]) {
                return false;
            } else {
                prevEnd = intervals[i][1];
            }
        }

        return true;
    }
};