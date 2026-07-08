class Solution {
public:
    int reverse(int x) {

        int reversedNumber = 0;

        while (x != 0) {

            // Extract the last digit
            int digit = x % 10;

            // Check if reversing the number will cause overflow
            if (reversedNumber > INT_MAX / 10 ||
                (reversedNumber == INT_MAX / 10 && digit > 7))
                return 0;

            // Check if reversing the number will cause underflow
            if (reversedNumber < INT_MIN / 10 ||
                (reversedNumber == INT_MIN / 10 && digit < -8))
                return 0;

            // Add the extracted digit to the reversed number
            reversedNumber = reversedNumber * 10 + digit;

            // Remove the last digit from the original number
            x /= 10;
        }

        return reversedNumber;
    }
};

/*
Time Complexity: O(log10(n))

Reason:
- In each iteration, one digit is removed from the number.
- If the number has d digits, the loop runs d times.
- Therefore, the running time depends on the number of digits.

Example:
Input: 12345

Iteration 1 -> 1234
Iteration 2 -> 123
Iteration 3 -> 12
Iteration 4 -> 1
Iteration 5 -> 0

Total iterations = 5

Time Complexity = O(log10(n))

------------------------------------------------

Space Complexity: O(1)

Reason:
- Only a few integer variables are used.
- No extra array, string, or data structure is created.

Space Complexity = O(1)
*/