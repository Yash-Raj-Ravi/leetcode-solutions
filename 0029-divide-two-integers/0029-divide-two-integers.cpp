class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) return 1;
        if (divisor == 1) return dividend;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;

        bool positive = (dividend < 0) == (divisor < 0);

        long long p = llabs((long long)dividend);
        long long q = llabs((long long)divisor);

        long long count = 0;

        while (p >= q) {
            p -= q;
            count++;
        }

        if (count > INT_MAX) {
            return positive ? INT_MAX : INT_MIN;
        }

        return positive ? (int)count : -(int)count;
    }
};