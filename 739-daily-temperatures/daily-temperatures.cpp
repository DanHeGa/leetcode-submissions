class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            while(!stk.empty() && temperatures[i] > temperatures[stk.top()]) {
                int idx = stk.top();
                int days = i - idx;
                ans[idx] = days;
                stk.pop();
            }

            stk.push(i);
        }

        return ans;
    }
};