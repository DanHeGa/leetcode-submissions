class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int globalMax = nums[0];
        int currMax = nums[0];
        int currMin = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int tmpCurrMax = currMax;
            currMax = max({nums[i], currMax * nums[i], currMin * nums[i]});
            currMin = min({nums[i], tmpCurrMax * nums[i], currMin * nums[i]});

            globalMax = max(globalMax, currMax);
        }
        
        return globalMax;
    }
};

/*
A negative number can flip a very high pos number, due to this flippings we need to track both minimum and maxmum (both local) with a global max. 
We have three options in each iteration:
 a. Start a new subarray
 b. Use the current maximum * n
 c. Use the current minimum * n

One of those three will be the next global maximum, and of course we always update both currMin and currMax as min/max(nums[i], currMax * n, currMin * n).
Use a tmp variable to use in currMin or else you would be using a currently updated currMax in the calculus of your currMin (see code for better understanding).
We finally return the globalMax, which we have been updating in each iteration with max(globalMax, currMax).

The solution will be O(n) in time, and O(1) in space.
*/