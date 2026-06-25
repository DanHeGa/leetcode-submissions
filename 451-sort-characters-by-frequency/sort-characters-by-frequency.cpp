class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freqs;
        for(char c : s) {
            freqs[c]++;
        }

        //get each unique char from the hashmap
       vector<char> uniques;
        for (auto freq : freqs) {
            uniques.push_back(freq.first);
        }

        sort(uniques.begin(), uniques.end(), [&](const char a, const char b) {
            return freqs[a] > freqs[b];
        });
        
        string res = "";
        for(char c : uniques) {
            res += string(freqs[c], c);
        }

        return res;
    }
};