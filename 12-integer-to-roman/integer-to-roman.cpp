class Solution {
public:
    string intToRoman(int num) {

        vector<pair<int, string>> romanValues = {
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"},
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40, "XL"},
            {10, "X"},
            {9, "IX"},
            {5, "V"},
            {4, "IV"},
            {1, "I"}
        };

        string roman = "";

        // Keep subtracting the largest possible Roman value
        for (auto &value : romanValues) {

            while (num >= value.first) {
                roman += value.second;
                num -= value.first;
            }
        }

        return roman;
    }
};

/*
⏱️ Time Complexity: O(1)

Reason:
- Roman numerals are limited to values from 1 to 3999.
- The list of Roman values contains only 13 entries.
- Therefore, the number of operations is constant.

💾 Space Complexity: O(1)

Reason:
- We use a fixed-size lookup table of 13 Roman numeral pairs.
- The output string has a maximum length of 15 characters.
- Hence, the extra space remains constant.
*/