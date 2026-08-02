class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        
        int rob1 = 0;
        int rob2 = 0;
        //try when omitting the last house
        for (int i = 0; i < nums.size() - 1; i++) {
            int tmp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        int robAttempt1 = rob2; //save rob attempt1 
        rob1 = 0; rob2 = 0;
        //now try when omittin the first house

        for (int i = 1; i < nums.size(); i++) {
            int tmp = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }

        return max(robAttempt1, rob2);
    }
};