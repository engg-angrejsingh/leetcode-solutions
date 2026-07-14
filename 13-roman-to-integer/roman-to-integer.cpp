class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000},
        };

        int result = 0;

        for (int i = 0; i < s.length(); i++){
            //If the current Roman numeral is simaller than the next one,
            // then will be subtrct is from the result.
            if (i + 1 < s.length() && romanValues[s[i]] < romanValues[s[i + 1]]){
                result -= romanValues[s[i]];
            }
            else{
                // Otherwise, add its value.
                result += romanValues[s[i]];
            }
        }

        return result;

    }
};

/*
⏱️ Time Complexity: O(n)

Reason:
- We traverse the Roman numeral string only once.
- Each character is processed exactly one time.

💾 Space Complexity: O(1)

Reason:
- The unordered_map stores the 7 Roman numeral symbols.
- Its size is constant and does not depend on the input length.
*/