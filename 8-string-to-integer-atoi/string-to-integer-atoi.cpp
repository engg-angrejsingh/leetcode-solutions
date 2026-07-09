class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.length();

        // Skip leading whitespaces
        while (i < n && s[i] == ' ')
            i++;

        // If string is empty after removing spaces
        if (i == n)
            return 0;

        // Check sign
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (s[i] == '+') {
            i++;
        }

        long long result = 0;

        // Convert digits
        while (i < n && isdigit(s[i])) {

            int digit = s[i] - '0';

            // Handle overflow
            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return sign * result;
    }
};

/*
Time Complexity: O(n)

Reason:
- We traverse the string only once.
- Each character is processed at most one time.
- Therefore, the overall time complexity is linear.

Space Complexity: O(1)

Reason:
- Only a few variables are used.
- No extra data structure is required.
- The space used does not depend on the input size.
*/