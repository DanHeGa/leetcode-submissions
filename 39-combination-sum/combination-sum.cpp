class Solution {
public:
    vector<vector<int>> res;
    void backHelper(int idx, vector<int> &sub, int sum, vector<int>& candidates, int &target) {
        if (sum == target) {
            res.push_back(sub);
            return;
        }
        
        for (int i = idx; i < candidates.size(); i++) {
            if (sum + candidates[i] > target) continue;
            sub.push_back(candidates[i]);
            backHelper(i, sub, sum + candidates[i], candidates, target);
            sub.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> sub;
        backHelper(0, sub, 0, candidates, target);
        return res;
    }
};