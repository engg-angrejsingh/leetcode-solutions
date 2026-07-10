class Solution {
public:
    bool isPalindrome(int x) {

        // Negative numbers are never palindromes
        if (x < 0)
            return false;

        int originalNumber = x;
        int reversedNumber = 0;

        while (x != 0) {

            // Extract the last digit
            int digit = x % 10;

            // Check for overflow
            if (reversedNumber > INT_MAX / 10 ||
                (reversedNumber == INT_MAX / 10 && digit > 7))
                return false;

            // Build the reversed number
            reversedNumber = reversedNumber * 10 + digit;

            // Remove the last digit
            x /= 10;
        }

        return originalNumber == reversedNumber;
    }
};

/*
Time Complexity: O(log10(n))

Reason:
- In each iteration, one digit is removed from the number.
- If the number has d digits, the loop runs d times.

Example:
Input: 12321

Iteration 1 -> 1232
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