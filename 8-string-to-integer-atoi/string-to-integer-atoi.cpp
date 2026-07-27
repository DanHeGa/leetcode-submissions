class Solution {
public:

    int lastMax = INT_MAX % 10;
    int lastMin = INT_MIN % 10;
    int maxNum = INT_MAX / 10;
    int minNum = INT_MIN / 10;

    int myAtoi(string s) {
        int i = 0; 
        int n = s.length();
        int ans = 0;
        bool flag = false;

        //avoid whitespaces
        while(i < n && s[i] == ' ') i++; 

        //get number sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') {
                flag = true;
            }
            i++;
        }
        
        //build number
        while(i < n && isdigit(s[i])) {
            int currInt = s[i] - '0';

            if (flag) {
                if (ans < minNum || ans == minNum && -currInt < lastMin) {
                    return INT_MIN;
                }

                ans *= 10;
                ans -= currInt;
            } else {
                if (ans > maxNum || ans == maxNum && currInt > lastMax) {
                    return INT_MAX;
                }

                ans *= 10;
                ans += currInt;

            }

            i++;
        }


        return ans;
    }
};