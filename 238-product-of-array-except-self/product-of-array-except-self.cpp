class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> leftToRight(n, 1);
        vector<int> rightToLeft(n, 1);
        leftToRight[0] = nums[0];
        rightToLeft[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            leftToRight[i] = leftToRight[i - 1] * nums[i];
        }

        for (int i = n - 2; i >= 0; i--) {
            rightToLeft[i] = rightToLeft[i + 1] * nums[i];
        }

        nums[0] = rightToLeft[1];
        nums[n - 1] = leftToRight[n - 2];
        for (int i = 1; i < n - 1; i++) {
            nums[i] = leftToRight[i - 1] * rightToLeft[i + 1];
        }

        return nums;
    }
};