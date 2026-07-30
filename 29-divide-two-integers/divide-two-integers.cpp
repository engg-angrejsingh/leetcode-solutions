class Solution {
public:
    int divide(int dividend, int divisor) {
        // Handle overflow case
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long dvd = labs((long long)dividend);
        long long dvs = labs((long long)divisor);

        long long ans = 0;

        while (dvd >= dvs) {
            long long temp = dvs;
            long long multiple = 1;

            while ((temp << 1) <= dvd) {
                temp <<= 1;
                multiple <<= 1;
            }

            dvd -= temp;
            ans += multiple;
        }

        // Apply sign
        if ((dividend < 0) ^ (divisor < 0))
            ans = -ans;

        return (int)ans;
    }
};

/*
⏱️ Time Complexity: O(log² n)

Reason:
- In each iteration, we subtract the largest possible multiple of the divisor.
- Finding that multiple requires repeated left shifts, which take O(log n).
- This process repeats O(log n) times in the worst case.

💾 Space Complexity: O(1)

Reason:
- Only a few extra variables are used.
- No additional data structures are required.
*/