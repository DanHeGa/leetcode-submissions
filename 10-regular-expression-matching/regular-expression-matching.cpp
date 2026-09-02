class Solution {
public:
    bool matchFunc(int i, int j, string& s, string& p, vector<vector<int>> &memo) {
        if (j >= p.length()) {
            return i == s.length();
        }
        //if you have that calculation, return it
        if (memo[i][j] != -1) {
            return memo[i][j] == 1 ? true : false;
        }

        int matching;
        if (j + 1 < p.length() && p[j + 1] == '*') {
            matching = matchFunc(i, j + 2, s, p, memo) || i < s.length() && (s[i] == p[j] || p[j] == '.') && matchFunc(i + 1, j, s, p, memo);
        } else {
            matching = i < s.length() && matchFunc(i + 1, j + 1, s, p, memo) && (s[i] == p[j] || p[j] == '.');
        }

        memo[i][j] == matching ? 1 : 0;
        return matching;
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        return matchFunc(0, 0, s, p, memo); 
    }
};

/*
   i=01 i=0
   s=aa p=a


*/