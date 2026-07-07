class Solution {
public:
    string convert(string s, int numRows) {
        int sizeofstring = s.length();
        // If the string has only one character, return it
        if (sizeofstring == 1)
            return s;

        // If there is only one row, Zigzag is the same as the original string
        if (numRows == 1)
            return s;

        // Create a string for each row
        vector<string> rows(numRows);

        int index = 0;

        while (index < sizeofstring) {

            // Move downward
            for (int row = 0; row < numRows && index < sizeofstring; row++) {
                rows[row].push_back(s[index++]);
            }

            // Move diagonally upward
            for (int row = numRows - 2; row > 0 && index < sizeofstring; row--) {
                rows[row].push_back(s[index++]);
            }
        }

        // Combine all rows
        string result = "";

        for (string row : rows) {
            result += row;
        }

        return result;
    }
};

/*
Time Complexity: O(n)

Reason:
- We visit each character of the string exactly once.
- Every character is added to one row.
- Therefore, the total number of operations is proportional to the length of the string.

Space Complexity: O(n)

Reason:
- We create extra strings to store the Zigzag rows.
- Together, these rows store all characters of the input string.
*/