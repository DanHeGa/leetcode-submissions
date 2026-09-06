class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int sum = 0;
        int minLen = INT_MAX;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            if (sum >= target) {
                while(sum >= target) {
                    minLen = min(minLen, right - left + 1);
                    sum -= nums[left];
                    left++;
                }
            }

        }

        return minLen != INT_MAX ? minLen : 0;
    }
};

/*
target = 7 
   i =  0 1 2 3 4 5
nums = [2,3,1,2,4,3]
                  r
                l
vars: sum, minLen

minLen = intmax, 4, 3, 2!! Answer

2+3 = target? no, keep l there and keep moving
5 + 1 = 7? no? keep moving r
6+2 = 7? no? but is greater! update minLen, and move l while also substracting l values from sum, until sum < target
8 - 2 = 6

6 + 4 = 10, update minLen if curr len less than min

moving left
10 - 3 = 7

[1, 2, 4] = 7, update minLen

7 + 10, move left
10 - 1 = 9
9 - 2 = 7

[4, 3] == 7, update minLen. FINISH!

*/