class Solution {
public:
    int recursiveBS(int left, int right, vector<int>& nums, int& numSize) {
        if (left == right) {
            return left;
        }

        int mid = left + (right - left) / 2;
        if (mid == numSize - 1 || nums[mid] > nums[mid + 1]) {
            return recursiveBS(left, mid, nums, numSize);
        }
        return recursiveBS(mid + 1, right, nums, numSize);
    }

    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        return recursiveBS(0, n, nums, n);
    }
};