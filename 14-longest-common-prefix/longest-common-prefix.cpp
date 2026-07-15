class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";

        int n = strs.size();

        for (int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0][i];
            bool match = true;

            // Compare with all other strings
            for (int j = 1; j < n; j++) {
                if (strs[j].size() <= i || strs[j][i] != ch) {
                    match = false;
                    break;
                }
            }

            if (!match) {
                break;
            } else {
                ans.push_back(ch);
            }
        }

        return ans;
    }
};

/*
Time Complexity: O(N * M)

N = Number of strings
M = Length of the shortest string (or the maximum common prefix checked)

- The outer loop traverses each character of the first string.
- The inner loop compares that character with the corresponding
  character in every other string.
- Hence, the overall time complexity is O(N * M).

Space Complexity: O(1)

- Only a few extra variables are used.
- (Ignoring the space required for the output string.)
*/