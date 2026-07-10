class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        //map queries indexes before sorting them
        unordered_map<int, int> queryRes(queries.size());
        vector<int> unorderedQueries = queries;

        sort(queries.begin(), queries.end());
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0]; 
        });

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int k = 0;
        for (int query : queries) {
            while(k < intervals.size() && query >= intervals[k][0]) {
                int interLen = intervals[k][1] - intervals[k][0] + 1;
                int interEndVal = intervals[k][1];
                pq.push({interLen, interEndVal});
                k++;
            }

            while(!pq.empty() && query > pq.top().second) {
                pq.pop();
            }

            queryRes[query] = pq.empty() ? -1 : pq.top().first;
        }

        vector<int> output(queries.size());
        for (int i = 0; i < unorderedQueries.size(); i++) {
            output[i] = queryRes[unorderedQueries[i]];
        }

        return output;
    }
};