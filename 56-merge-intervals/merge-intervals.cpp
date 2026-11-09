class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //sort in asc order
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> res = {intervals[0]};

        for (int i = 1; i < intervals.size(); i++) {
            vector<int> currInter = intervals[i];
            if (currInter[0] <= res.back()[1]) {
                res.back()[0] = min(res.back()[0], currInter[0]);
                res.back()[1] = max(res.back()[1], currInter[1]);
            } else{ 
                res.push_back(currInter);
            }
        }

        return res;
    }
};