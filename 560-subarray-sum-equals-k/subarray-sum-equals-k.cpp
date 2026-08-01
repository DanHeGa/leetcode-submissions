class Solution {
public:                      
    int subarraySum(vector<int>& nums, int k) { //[1,1,1] k = 2
        unordered_map<int, int> freq = {
            {0, 1}
        };
        //{1: 1}, {2: 1}, {3: 1}

        int ans = 0;//2
        int currSum = 0; //3
        for (int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            int breakPt = currSum - k; //1
            if (freq.contains(breakPt)) {
                ans += freq[breakPt];
            }

            freq[currSum]++;
        }

        return ans;
    }
};

/*
[1,1,1] k = 2
j = 2
sum[:j] = sum[:i] + k
sum[:j] - k = sum[:i]

[2, 1, 2] k = 2

*/