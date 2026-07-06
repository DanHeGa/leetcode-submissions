class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[1] < b[1];
        });

        int prevEnd = intervals[0][1];
        int overlaps = 0;
        for (int i = 1; i < intervals.size(); i++) {
            if (prevEnd > intervals[i][0]) {
                overlaps++;
            } else {
                prevEnd = intervals[i][1];
            }
        }   

        return overlaps;
    }
};