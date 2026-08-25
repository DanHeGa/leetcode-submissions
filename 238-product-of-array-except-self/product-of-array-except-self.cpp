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

        for (int i = 0; i < n; i++) {
            if (i == 0) {
                nums[i] = rightToLeft[i + 1];
            } else if (i == n - 1) {
                nums[i] = leftToRight[i - 1];
            } else {
                nums[i] = leftToRight[i - 1] * rightToLeft[i + 1];
            }
        }

        return nums;
    }
};