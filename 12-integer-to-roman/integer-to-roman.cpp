class Solution {
private:

    // Convert units digit (0-9) to Roman numeral
    string unitsDigitToRoman(int digit) {
        switch (digit) {
            case 0: return "";
            case 1: return "I";
            case 2: return "II";
            case 3: return "III";
            case 4: return "IV";
            case 5: return "V";
            case 6: return "VI";
            case 7: return "VII";
            case 8: return "VIII";
            case 9: return "IX";
        }
        return "";
    }

    // Convert tens digit (0-9) to Roman numeral
    string tensDigitToRoman(int digit) {
        switch (digit) {
            case 0: return "";
            case 1: return "X";
            case 2: return "XX";
            case 3: return "XXX";
            case 4: return "XL";
            case 5: return "L";
            case 6: return "LX";
            case 7: return "LXX";
            case 8: return "LXXX";
            case 9: return "XC";
        }
        return "";
    }

    // Convert hundreds digit (0-9) to Roman numeral
    string hundredsDigitToRoman(int digit) {
        switch (digit) {
            case 0: return "";
            case 1: return "C";
            case 2: return "CC";
            case 3: return "CCC";
            case 4: return "CD";
            case 5: return "D";
            case 6: return "DC";
            case 7: return "DCC";
            case 8: return "DCCC";
            case 9: return "CM";
        }
        return "";
    }

    // Convert thousands digit (0-3) to Roman numeral
    string thousandsDigitToRoman(int digit) {
        switch (digit) {
            case 0: return "";
            case 1: return "M";
            case 2: return "MM";
            case 3: return "MMM";
        }
        return "";
    }

public:
    string intToRoman(int num) {

        string roman = "";

        // Add units digit
        int digit = num % 10;
        roman = unitsDigitToRoman(digit) + roman;
        num /= 10;

        // Add tens digit
        digit = num % 10;
        roman = tensDigitToRoman(digit) + roman;
        num /= 10;

        // Add hundreds digit
        digit = num % 10;
        roman = hundredsDigitToRoman(digit) + roman;
        num /= 10;

        // Add thousands digit
        digit = num % 10;
        roman = thousandsDigitToRoman(digit) + roman;

        return roman;
    }
};

/*
⏱️ Time Complexity: O(1)

Reason:
- Roman numerals are limited to numbers from 1 to 3999.
- We process at most four digits.
- Each digit is converted using a constant-time switch statement.

💾 Space Complexity: O(1)

Reason:
- Only a few variables are used.
- The output string has a maximum length of 15 characters ("MMMDCCCLXXXVIII").
- Therefore, the extra space remains constant.
*/