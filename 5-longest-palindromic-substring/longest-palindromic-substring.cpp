class Solution {
public:

    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> palindrome(n, vector<bool>(n, true));
        int maxLen = 1;
        int maxIdx = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                palindrome[i][j] = s[i] == s[j] && palindrome[i + 1][j - 1];
                if (palindrome[i][j]) {
                    int palLen = (j - i + 1);
                    if (palLen > maxLen) {
                        maxLen = palLen;
                        maxIdx = i;
                    }
                }
            }
        }
        

        cout << s.substr(maxIdx, maxLen) << endl;
        return s.substr(maxIdx, maxLen);
    }
};