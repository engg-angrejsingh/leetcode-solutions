class Solution {
public:

    int start = 0;
    int maxLength = 1;

    void expand(string& s, int left, int right) {

        while (left >= 0 &&
               right < s.length() &&
               s[left] == s[right]) {

            if (right - left + 1 > maxLength) {
                maxLength = right - left + 1;
                start = left;
            }

            left--;
            right++;
        }
    }

    string longestPalindrome(string s) {

        if (s.empty())
            return "";

        for (int i = 0; i < s.length(); i++) {

            // Odd length palindrome
            expand(s, i, i);

            // Even length palindrome
            expand(s, i, i + 1);
        }

        return s.substr(start, maxLength);
    }
};

/*
Time Complexity: O(n²)

Reason:
- We expand around every character.
- In the worst case, each expansion may scan almost the entire string.
- Therefore, total complexity is O(n²).

Space Complexity: O(1)

Reason:
- Only a few variables are used.
- No extra data structure is created.
*/