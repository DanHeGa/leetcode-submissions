class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> pairs = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int res = 0;
        int n = s.length();
        int i = 0;
        while(i < n) {
            if ((s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X')) ||
                 s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C') ||
                 s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M')
            ) {
                res += pairs[s[i + 1]] - pairs[s[i]];
                i += 2;
            } else {
                res += pairs[s[i]];
                i++;
            }
        }

        return res;
    }
};