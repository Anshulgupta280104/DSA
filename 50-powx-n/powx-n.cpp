class Solution {
public:

    double solve(double x, long long n)
    {
        // base case
        if(n == 0)
            return 1;

        double half = solve(x, n / 2);

        // even power
        if(n % 2 == 0)
            return half * half;

        // odd power
        else
            return x * half * half;
    }

    double myPow(double x, int n) {

        long long N = n;

        // handle negative power
        if(N < 0)
        {
            x = 1 / x;
            N = -N;
        }

        return solve(x, N);
    }
};