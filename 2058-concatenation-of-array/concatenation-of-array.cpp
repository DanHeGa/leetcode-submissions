class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n * 2);

        int k = 0;
        for (int i = 0; i < n * 2; i++) {
            ans[i] = nums[k];
            k = (k + 1) % n;
        }

        return ans;
    }
};