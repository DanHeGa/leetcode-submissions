class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = -1; //set initially to -1, because what if k that reaks desc order is 0 huh.
        int n = nums.size();

        //get pointer to desc order breaker
        for (int k = n - 2; k >= 0; k--) {
            if (nums[k + 1] > nums[k]) {
                i = k;
                break;
            }
        }

        if (i != -1) {
            for (int j = n - 1; j > i; j--) {
                if (nums[j] > nums[i]) {
                    int tmp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = tmp;
                    break;
                }
            }
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};

//[1, 2, 5, 4, 3]