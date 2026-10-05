class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        //save all elements in a list of pairs (num, vecIdx)
        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums.size(); i++) {
           for (int num : nums[i]) {
                pairs.push_back({num, i});
           }
        }

        //sort based on num, NOT on nums VecIdx,
        sort(pairs.begin(), pairs.end());

        //sliding window to minimize range of numbers where we have numbers from ALL the nums vectors
        int n = pairs.size(); 

        int left = 0;
        int inclusiveCount = 0;
        
        vector<int> minRange = {0, INT_MAX};
        unordered_map<int, int> numCount; //should all be 1 in the ideal case
        for (int right = 0; right < n; right++) {
            numCount[pairs[right].second]++;
            inclusiveCount++;

            while(numCount.size() == nums.size()) {
                int a = pairs[left].first;
                int b = pairs[right].first;

                int c = minRange[0];
                int d = minRange[1];

                if (b - a < d - c || (a < c && b - a == d - c)){
                    minRange = {a, b};
                }

                //shrink window
                int leftVec = pairs[left].second;
                numCount[leftVec]--;
                if (numCount[leftVec] == 0) {
                    numCount.erase(leftVec);
                }

                left++;
            }
        }

        return minRange;
    }
};