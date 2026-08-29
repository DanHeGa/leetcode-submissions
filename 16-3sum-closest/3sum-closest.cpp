class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        long ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1; 
            int right = n - 1;
            int minDiff = INT_MAX;
            while(left < right) {
                int op = nums[i] + nums[left] + nums[right];

                if (op == target) {
                    return op;
                } else if (abs(target - op) < abs(target - ans)) {
                    ans = op;
                }

                if (op > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }

        return ans;
    }
};

/*
    i =  0  1 2  3
 nums = [-1,2,1,-4] target = 1 // n = 4
--this is how you would do 3 sum normal, NOT closest--
 iterate from 0 to < n - 2
 i = 0
    resultant = 1 - 1 = 0, so now we need to get to 0
    search from 1 to n using binary search

*/