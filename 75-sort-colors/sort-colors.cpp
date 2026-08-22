class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> freqs(3, 0);
        for (int num : nums) {
            freqs[num]++;
        }

        int n = nums.size();
        int i = 0;
        int k = 0;
        while(i < n) {
            if (freqs[k] == 0) {
                k++;
                continue;
            }
            int currNum = k;
            nums[i] = currNum;
            freqs[k]--;
            i++;
        }
    }
};


/*
[2,0,2,1,1,0]

mp = {
    0: 2,
    1: 2,
    2: 2
}

i = 0


*/