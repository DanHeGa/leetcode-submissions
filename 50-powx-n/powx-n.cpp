class Solution {
public:
    //function with recursive approach
    //it goes bottom to top
    double customPow(double x, int n) { //x^n
        if (n == 0) return 1; //all num to the power of 1 is zero.

        double half = customPow(x, n / 2);

        if (n % 2 == 0) { //even exponent
            return half * half;
        } else { // odd
            return x * (half * half);
        }
    }

    double iterativePow(double x, long long n) {
        double ans = 1;
        double base = x;

        while(n > 0) {
            if (n & 1) {
                ans *= base;
            }

            base *= base;
            n >>= 1;
        }

        return ans;
    }

    //iterative approach, top to bottom
    double myPow(double x, int n) {
        long long N = n; //for overflowing cases
    
        if (n < 0) {
            return 1 / iterativePow(x, -N);
        } else {
            return iterativePow(x, N);
        }
    }
};