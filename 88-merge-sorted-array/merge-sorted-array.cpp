class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1; 
        int j = n - 1; 
        int k = m + n - 1;
        while(j >= 0) { //while nums 2 still has elements left to put in n1
            if (i >= 0 && nums1[i] >= nums2[j]) {
                nums1[k] = nums1[i];
                i--;
            } else {
                nums1[k] = nums2[j];
                j--;
            }
            k--;
        }
    }
};

/*
             i      
nums1 = [1,2,3,0,0,0]
             j
nums2 = [2,5,6]
k = 6;
*/