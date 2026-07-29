class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0; 
        int right = nums.size() - 1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            //is from left to mid sorted?
            if (nums[left] <= nums[mid]) {
                //check if target is within that range
                if (target >= nums[left] && target <= nums[mid]) {
                    right = mid - 1;
                } else {
                    //if it is NOT in that range (left - mid), move left 
                    left = mid + 1;
                }
            } else {
                //if left vector not in asc order, check if target is in right part of the vector
                if (target >= nums[mid] && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

/*
og = [0,1,2,4,5,6,7]
input (rotated) = [4, 5, 6, 7, 0, 1, 2]
target = 0

*/