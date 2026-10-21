class Solution {
public:
    vector<vector<int>> res;
    void backHelper(int idx, vector<int> &sub, int sum, vector<int>& candidates, int &target) {
        if (sum == target) {
            res.push_back(sub);
            return;
        }

        if (idx >= candidates.size() || sum > target){
            return;
        }

        sub.push_back(candidates[idx]);
        backHelper(idx, sub, sum + candidates[idx], candidates, target);

        sub.pop_back();
        backHelper(idx + 1, sub, sum, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sub;
        backHelper(0, sub, 0, candidates, target);
        return res;
    }
};