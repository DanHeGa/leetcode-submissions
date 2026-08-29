class Solution {
public:
    bool check(vector<int>& nums) {
        if (nums.size() == 1) {
            return true;
        }
        int n = nums.size(); 
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }


        return count > 1 ? false : true;
    }
};