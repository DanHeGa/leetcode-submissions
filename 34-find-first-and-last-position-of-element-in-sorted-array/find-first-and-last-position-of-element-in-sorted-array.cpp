class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size() - 1;

        int left = 0;
        int right = n;

        int firstPos = -1;
        int lastPos = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                if (mid - 1 >= 0 && nums[mid - 1] == target) {
                    right = mid - 1;
                } else {
                    firstPos = mid;
                    break;
                }
            }

            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }

        //look for the last position
        left = 0; right = n; //set variables to initial state to re-do binary search for lastpos
        while(left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                if (mid + 1 <= n && nums[mid + 1] == target) {
                    left = mid + 1;
                } else {
                    lastPos = mid;
                    break;
                }
            }
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }

        vector<int> ans = {firstPos, lastPos};
        return ans;
    }
};

/*
0           5
[5,7,7,8,8,10] t = 8
       m 
       

*/