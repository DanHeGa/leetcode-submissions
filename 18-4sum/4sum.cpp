class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        vector<vector<int>> res;

        sort(nums.begin(), nums.end());

        int n = nums.size();
        for (int i = 0; i < n - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) continue; //avoid duplicates

            for (int j = i + 1; j < n - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                int left = j + 1;
                int right = n - 1;

                while(left < right) {
                    long long op = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (op == target){
                        vector<int> subRes = {nums[i], nums[j], nums[left], nums[right]};
                        res.push_back(subRes);
                        left++; //move them cause u already considered them
                        right--;

                        while(left < right && nums[left] == nums[left - 1]) {
                            left++;
                        }
                        while(right > left && nums[right] == nums[right + 1]){
                            right--;
                        }

                    } else if (op < target) {
                        left++;
                    } else if (op > target) {
                        right--;
                    }
                }
            }
        }

        return res;
    }
};

