class Solution {
public:
    const int MOD = 1e9 + 7;

    int countAnagrams(string s) {
        istringstream ss(s);
        string word;
        long totalAnagrams = 1;
        long totalFreqs = 1;

        while(ss >> word) {
            vector<int> freq(26, 0);
            for (int i = 1; i <= word.size(); i++) {
                int charIdx = word[i - 1] - 'a';
                freq[charIdx]++;

                totalAnagrams = totalAnagrams * i % MOD;
                totalFreqs = totalFreqs * freq[charIdx] % MOD;
            }
        }


        return totalAnagrams * binaryExp(totalFreqs, MOD - 2) % MOD;
    }

    long binaryExp(long base, long exponent) {
        
        long res = 1L;
        while (exponent > 0) {
            if (exponent % 2 != 0) {
                res = res * base % MOD;
            }

            base = base * base % MOD;
            exponent /= 2;
        }

        return res;
    }
};