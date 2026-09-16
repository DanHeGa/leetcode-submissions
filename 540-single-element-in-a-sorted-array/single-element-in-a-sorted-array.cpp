class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int n = nums.size();
        if (nums.size() == 1) return nums[0];

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if (mid % 2 == 0) { //mid is even
                if (mid - 1 >= 0 && nums[mid - 1] == nums[mid]) {
                    right = mid - 1;
                } else if (mid + 1 < n && nums[mid + 1] == nums[mid]) {
                    left = mid + 1;
                } else {
                    return nums[mid];
                }
            } else { //mid is odd
                if (mid - 1 >= 0 && nums[mid - 1] == nums[mid]) {
                    left = mid + 1;
                } else if (mid + 1 < n && nums[mid + 1] == nums[mid]){
                    right = mid - 1;
                } else {
                    return nums[mid];
                }
            }
        }

        return left;
    }
};

/*

   i =  0 1 2 3 4 5 6 7 8  len = 9 
nums = [1,1,2,3,3,4,4,8,8]



left = 0, right = 8, mid = 4

*/