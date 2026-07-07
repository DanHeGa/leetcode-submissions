class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        int maxEndTime = 0;
        for (auto &inter : intervals) {
            maxEndTime = max(maxEndTime, inter[1]);
        }

        vector<int> schedule(maxEndTime + 1, 0);
        for (auto &inter : intervals) {
            schedule[inter[0]]++;
            schedule[inter[1]]--;
        }

        int maxSum = 0;
        int prefixSum = 0;
        for(int i = 0; i < schedule.size(); i++) {
            prefixSum += schedule[i];
            maxSum = max(maxSum, prefixSum);
        }

        return maxSum;
    }
};