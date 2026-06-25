class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqs;
        for(char c : s) {
            freqs[c]++;
        }

        //get each unique char from the hashmap
        int n = s.length();
        vector<vector<char>> buckets(n + 1);
        
        for(auto freq : freqs) {
            buckets[freq.second].push_back(freq.first);
        }

        string res = "";
        for(int i = n; i >= 0; i--) {
            for(char c : buckets[i]) {
                res += string(i, c);
            }
        }

        return res;
    }
};