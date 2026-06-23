class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int right = 0;
        int left = 0;
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> res;

        while(right < n) {
            //push element to window heap
            pq.push({nums[right], right});

            //clean heap from elements out of window range
            while(pq.top().second < left){
                pq.pop();
            }

            //register window max if window is possible to form
            if ((right - left + 1) == k) {
                int windowMax = pq.top().first;
                res.push_back(windowMax);
                left++;
            }

            right++;
        }

        return res;
    }
};

/*
input nums = [5  6  -1 -3  5  3  6  7], k = 3

0   1   2   3  4  5  6  7 indexes
l
            r
[1  3  -1] -3  5  3  6  7       3   
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

r < n (size of nums) O(n logn)
    if (r - l + 1 > k)
        left++;
        res.pushback(heap.top) res has O(n % k), n size of nums, k num of windows
        if (nums[left - 1] == heap.top()) 
            pop();    

    heap.push(nums[r]); heap has O(k) k = window size
    r++;

return res
*/