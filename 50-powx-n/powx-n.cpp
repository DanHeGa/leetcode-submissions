class Solution {
public:
    double customPow(double x, int n) { //x^n
        if (n == 0) return 1; //all num to the power of 1 is zero.

        double half = customPow(x, n / 2);

        if (n % 2 == 0) { //even exponent
            return half * half;
        } else { // odd
            return x * (half * half);
        }
    }

    double myPow(double x, int n) {
        if( n < 0 ) {
            double res = customPow(x, n);
            return 1 / res;
        } else {
            return customPow(x, n);
        }
    }
};