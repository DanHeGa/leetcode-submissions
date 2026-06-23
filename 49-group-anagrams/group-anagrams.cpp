class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> res;

        for (string word : strs) {
            string orgWord = word;
            sort(word.begin(), word.end());
            mp[word].push_back(orgWord);
        }

        for (auto [head, anagrams] : mp) {
            res.push_back(anagrams);
        }

        return res;
    }
};