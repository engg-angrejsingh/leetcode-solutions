class Solution {
public:
    vector<string> result;

    void solve(int index, string &digits, string &current, vector<string> &mapping) {

        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char letter : letters) {
            current.push_back(letter);
            solve(index + 1, digits, current, mapping);
            current.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return {};

        vector<string> mapping = {
            "",
            "",
            "abc",
            "def",
            "ghi",
            "jkl",
            "mno",
            "pqrs",
            "tuv",
            "wxyz"
        };

        string current = "";

        solve(0, digits, current, mapping);

        return result;
    }
};

/*
⏱️ Time Complexity: O(4ⁿ × n)

Reason:
- At most 4 choices for each digit.
- Up to 4ⁿ combinations are generated.
- Building each combination takes O(n).

💾 Space Complexity: O(n)

Reason:
- The recursion stack and current string require O(n) auxiliary space.
- The output list is not included in the space complexity.
*/