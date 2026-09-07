class Solution {
public:
    int divide(int dividend, int divisor) {
        //handle edge cases
        if (dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        } else if (divisor == 1) {
            return dividend;
        }

        //get sign, if both have the same sign, the result will be positive
        bool sign = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);

        //make em negative, of course, it they are oiginally positive, this to avoid overflow
        dividend = dividend < 0 ? dividend : -dividend;
        divisor = divisor < 0 ? divisor : -divisor;

        //start substraction process
        int res = 0;
        while(dividend <= divisor) {
            int currDivisor = divisor;
            int count = 1;
            while(divisor >= INT_MIN && dividend <= (divisor << 1)) {
                currDivisor <<= 1;
                count <<= 1;
            }
            dividend -= currDivisor;
            res += count;
        }

        return sign ? res : -res;
    }
};