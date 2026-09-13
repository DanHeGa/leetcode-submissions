class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        if (nums2.size() > nums1.size()) {
            //nums1 will always be the larger
            vector<int> tmp = nums1;
            nums1 = nums2;
            nums2 = tmp;
        }
        
        unordered_set<int> set2(nums2.begin(), nums2.end());

        vector<int> res;
        for (int ele : nums1) {
            if (set2.contains(ele)) {
                res.push_back(ele);
                set2.erase(ele);
            }
        }

        return res;
    }
};