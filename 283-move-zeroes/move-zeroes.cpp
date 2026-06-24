class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int j = 0;

        int n = nums.size();
        while(i < n) {
            if (nums[i] != 0) {
                nums[j] = nums[i];
                j++;
            }

            i++;
        }

        cout << "j ended in " << j << endl;
        while(j < n) {
            nums[j] = 0;
            j++;
        }
    }
};

/*
nums = [0,1,0,3,12]
        i
        j
*/