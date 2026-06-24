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

        string sKey = "", tKey = "";
        for (int i = 0; i < 26; i++) {
            sKey += to_string(freqS[i]) + "#";
            tKey += to_string(freqT[i]) + "#";
        }

        return sKey == tKey;
    }
};