class Solution {
public:
    void reverseVec(vector<int>& nums, int left, int right) {
        while(left < right) {
            int aux = nums[left];
            nums[left] = nums[right];
            nums[right] = aux;
            left++;
            right--;
        }
    }

    void rotate(vector<int>& nums, int k) {
        if (k == 0 || nums.size() == 1) {
            return;
        }

        int n = nums.size();
        k = k % n;
        //reverse whole vec
        reverseVec(nums, 0, n - 1);
        //reverse only from 0 to k - 1
        reverseVec(nums, 0, k - 1);
        //reverse from k to n - 1
        reverseVec(nums, k, n - 1);
    }
};