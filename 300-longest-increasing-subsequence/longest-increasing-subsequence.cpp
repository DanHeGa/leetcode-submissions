class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //vector to represent the longest increasing subsequence
        vector<int> tails; //O(n) - space

        int maxLis = 1;
        for (int num : nums) { 
            auto lowerB = lower_bound(tails.begin(), tails.end(), num);

            if (lowerB == tails.end()) { //no other element is >= num
                tails.push_back(num);
            } else {
                *lowerB = num;
            }
        }

        return tails.size();
    }
};