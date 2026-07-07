class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        //save meetings start and end times in order, like if we were using the maxEndtime length vector, but only analyzing the times when there is ac actual event/meeting staring/ending.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> schedule;
        for (auto &inter : intervals) {
            schedule.push({inter[0], 1});
            schedule.push({inter[1], -1});
        }

        int maxSum = 0;
        int prefixSum = 0;
        while(!schedule.empty()) {
            pair<int, int> currEvent = schedule.top();
            schedule.pop(); 
            prefixSum += currEvent.second;
            maxSum = max(maxSum, prefixSum);
        }

        return maxSum;
    }
};