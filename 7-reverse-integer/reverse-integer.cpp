class Solution {
public:
    int reverse(int x) {
        int res = 0;
        int intMax = INT_MAX / 10;
        int intMin = INT_MIN / 10;
        int lastMaxDgt =  INT_MAX % 10;
        int lastMinDgt = INT_MIN % 10;

        while(x) {
            int newDigit = x % 10; //get last digit from input num
            x = x / 10; //move from 123 to 12 for exmple
            if (res > intMax || res == intMax && newDigit > lastMaxDgt) { 
                return 0;
            }
            if (res < intMin || res == intMin && newDigit < lastMinDgt) {
                return 0;
            }

            res = res * 10 + newDigit;
        }

        return res;
    }
};


/*
res = 0;
in = 123

x = mod(in, 10) -> 3
res = res * 10 + x; -> 0 * 10 + 3 = 3
321

*/