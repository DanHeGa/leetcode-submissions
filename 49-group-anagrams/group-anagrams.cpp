class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;

        for (string word : strs) {
            vector<int> freqC(26, 0);
            for (char letter : word) {
                freqC[letter - 'a']++;
            }

            string key = "";
            for (int count : freqC) { //O(1) becauase it's a fixed size vector
                key += to_string(count) + "#";
            }

            mp[key].push_back(word);
        }

        for (auto [head, anagrams] : mp) {
            res.push_back(anagrams);
        }

        return res;
    }
};