class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> mp;
        vector<vector<string>> res;

        for (string word : strs) {
            vector<int> freqC(26, 0);
            for (char letter : word) {
                freqC[letter - 'a']++;
            }

            mp[freqC].push_back(word);
        }

        for (auto [head, anagrams] : mp) {
            res.push_back(anagrams);
        }

        return res;
    }
};