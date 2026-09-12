class Solution {
public:
    int sumDivs(vector<int>& nums, int sum) {
        int divisions = 1; 
        int currSum = 0;

        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            if (currSum > sum) {
                divisions++;
                currSum = nums[i];
            }
        }

        return divisions;
    }

    int splitArray(vector<int>& nums, int k) {
        //get search space limits
        int minSum = 0; //max num of nums
        int maxSum = 0; //sum of nums
        for (int num : nums) {
            minSum = max(minSum, num);
            maxSum += num;
        }

        //binary search in limits (minSum-maxSum) because its what we want to minimize
        int left = minSum;
        int right = maxSum;
        while(right > left) {
            int mid = left + (right - left) / 2;

            int divisions = sumDivs(nums, mid);
            if (divisions > k) {
                left = mid + 1;
            } else { //divisions <= k, so we can keep on minimizing
                right = mid;
            }
        }

        return left;
    }
};