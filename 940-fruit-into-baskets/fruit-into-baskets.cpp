class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> freqs;

        int maxSize = 0;
        int left = 0;
        for (int right = 0; right < fruits.size(); right++) {
            freqs[fruits[right]]++;
            while(freqs.size() > 2) {
                int currFruit = fruits[left];
                freqs[currFruit]--;
                if (freqs[currFruit] == 0) {
                    freqs.erase(currFruit);
                }
                left++;
            }

            maxSize = max(maxSize, right - left + 1);
        }

        return maxSize;
    }
};

/*
rephrase: looking for the longest contiguous subarray containing 
at most 2 distinct values
i =  0 1 2 3
    [0,1,2,2]
       l
           r
    maxSize = 3  which is (3 - 1) + 1, when r = 3, and left = 1
    set = {1, 2}
*/