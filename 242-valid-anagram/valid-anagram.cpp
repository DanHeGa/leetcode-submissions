class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> freqS(26, 0);
        vector<int> freqT(26, 0);

        for (char letter : s) {
            freqS[letter - 'a']++;
        }

        for(char letter : t) {
            freqT[letter - 'a']++;
        }

        return freqS == freqT;
    }
};