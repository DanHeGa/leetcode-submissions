class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //nums = [2,2,3,4] n = 4, 
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int tripletCnt = 0;
        int count = 0;
        for (int i = 0; i < n - 2; i++) {
            int k = 0;
            for (int j = i + 1; j < n - 1; j++) {
                int op = nums[i] + nums[j]; //a + b

                //start binary search to find third triplet element
                int left = j + 1; 
                int right = n - 1;
                while(left <= right && right < n) {
                    int mid = left + (right - left) / 2;

                    if (nums[mid] < op) {
                        left = mid + 1;
                    } else if (nums[mid] >= op) {
                        right = mid - 1;
                    }
                }
                k = left - j - 1;
                count += k;
            }
        }

        return count;
    }
};