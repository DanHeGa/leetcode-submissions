class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

       //count each num frequency
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

       //order them through the use of a priority queue
        priority_queue<pair<int, int>> ordered_freqs;
        for (auto [number, frequency] : freq){
            pair<int, int> numCount = {frequency, number};
            ordered_freqs.push(numCount);
        }

        //get top k frequent elements
        vector<int> res;
        for (int i = 0; i < k; i++) { 
            res.push_back(ordered_freqs.top().second);
            ordered_freqs.pop();
        }

        return res;
    }
};