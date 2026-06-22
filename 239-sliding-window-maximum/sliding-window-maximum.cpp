class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int r = 0;
        int l = 0;
        int n = nums.size();

        priority_queue<pair<int, int>> pq;
        while(r <= n) {
            if ((r - l + 1) > k) {
                l++;
                int windowMax = pq.top().first;
                res.push_back(windowMax);
                while(pq.size() > 0 && pq.top().second < l) {
                    pq.pop();
                }

            }

            if (r == n) {
                break;
            } else {
                pq.push({nums[r], r});
                r++;
            }
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