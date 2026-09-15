class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();

        stack<int> stk; //bottom to top decreasing stack
        vector<int> res(n, -1);

        for (int i = 2 * n - 1; i >= 0; i--) {
            int currIdx = i % n;
            if (stk.empty()) {
                stk.push(nums[currIdx]);
                continue;
            }

            while(!stk.empty() && stk.top() <= nums[currIdx]) {
                stk.pop();
            }

            //next element, if existant, should be the next greater element of nums[i]
            if (!stk.empty() && i < n) {
                res[currIdx] = stk.top();
            } 

            stk.push(nums[currIdx]);
        } 

        return res;
    }
};