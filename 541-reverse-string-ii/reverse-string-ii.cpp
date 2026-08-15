class Solution {
public:
    void reverseString(string &s, int l, int r) {
        while(l < r) {
            char aux = s[r];
            s[r] = s[l];
            s[l] = aux;
            r--;
            l++;
        }
    }

    string reverseStr(string s, int k) {
        int n = s.length();
        if (n == 1) {
            return s;
        }

        if (n < k) {
            reverseString(s, 0, n - 1);
            return s;
        }

        int left = 0;
        for (int right = 0; right < n; right++) {
            if (right - left + 1 == 2 * k) {
                reverseString(s, left, left + k - 1);
                left = right + 1;
            }
        }

        int currLen = (n - 1) - left + 1;
        if (currLen < 2 * k && currLen >= k) {
            reverseString(s, left, left + k - 1);
        } else if (currLen < k) {
            reverseString(s, left, n - 1);
        }

        return s;
    }
};