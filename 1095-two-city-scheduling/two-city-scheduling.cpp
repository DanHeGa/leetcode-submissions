class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size(); //will sort them based on absolute difference
        vector<pair<int, int>> diffs(n);
        for (int i = 0; i < n; i++) {
            int diff = costs[i][0] - costs[i][1];
            diffs[i] = {diff, i}; //save diff and index
        }

        sort(diffs.begin(), diffs.end());

        int counter = 0;
        int summatory = 0;
        for (auto [diff, costIdx] : diffs) {
            if (counter < n / 2) {
                summatory += costs[costIdx][0];
            } else {
                summatory += costs[costIdx][1];
            }
            counter++;
        }

        return summatory;
    }
};