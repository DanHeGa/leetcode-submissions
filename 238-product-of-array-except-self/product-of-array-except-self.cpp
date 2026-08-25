class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int leftProd = 1;
        int rightProd = 1;
        vector<int> res(n);

        for (int i = 0; i < n; i++) { //crucial to uodate AFTER setting res[i]
            res[i] = leftProd;
            leftProd *= nums[i];
        }

        for (int i = n - 1; i >= 0; i--) {
            res[i] *= rightProd;
            rightProd *= nums[i];
        }

        return res;
    }
};