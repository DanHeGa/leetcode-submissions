class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());

        vector<int> res;
        for (int ele : set1) {
            if (set2.contains(ele)) {
                res.push_back(ele);
            }
        }

        return res;
    }
};