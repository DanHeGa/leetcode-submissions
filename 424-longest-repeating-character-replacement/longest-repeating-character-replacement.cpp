class Solution {
public:
    int characterReplacement(string s, int k) {
        //have a frequency map
        unordered_map<char, int> freq;

        int maxFreq = 0;

        int l = 0;
        for (int r = 0; r < s.length(); r++) {
            freq[s[r]]++;
            maxFreq = max(maxFreq, freq[s[r]]);

            int windowSize = r - l + 1;
            if (windowSize - maxFreq > k) {
                freq[s[l]]--;
                l++;
            }
        }

        return s.length() - l;
    }
};

/*
i = 0123   
    ABBA

*/