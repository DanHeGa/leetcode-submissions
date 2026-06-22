class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> uniques;

        int r = 0; 
        int l = 0;

        int n = s.length();
        int maxLen = 0;
        while(r < n) {
            while (uniques.find(s[r]) != uniques.end()) {
                uniques.erase(s[l]);
                l++;
            }

            maxLen = max(maxLen, r - l + 1);
            
            uniques.insert(s[r]);
            r++;
        }

        return maxLen;
    }
};

/*

set = {a, b, c}
maxLen = 3 

"abcabcbb"
   r
  l
len = 3
each time we increment l, we incremment len; 

maxlen= max(maxlen, len)
each time we move r, we increment maxlen if the inner variable is more than maxLen
*/