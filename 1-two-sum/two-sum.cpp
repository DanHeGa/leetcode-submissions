class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        vector<int> res;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int op = target - nums[i];

            if (numMap.find(nums[i]) != numMap.end()) {
                int idx = numMap[nums[i]];
                res = {idx, i};
                return res;
            } else {
                numMap[op] = i;
            }
        }

        return res;
    }
};

/*
[2,7,11,15] t = 9

op = t - nums[i]

op = 7 

{
    7: 0,
    2: 1
}


*/