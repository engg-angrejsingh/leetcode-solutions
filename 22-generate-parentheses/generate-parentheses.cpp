class Solution {
public:
    void solve(int open, int close, int n, string curr, vector<string>& ans) {
        if (curr.size() == 2 * n) {
            ans.push_back(curr);
            return;
        }

        // Add '(' if we still can
        if (open < n)
            solve(open + 1, close, n, curr + '(', ans);

        // Add ')' only if it won't make the string invalid
        if (close < open)
            solve(open, close + 1, n, curr + ')', ans);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, n, "", ans);
        return ans;
    }
};

/*
⏱️ Time Complexity: O(4ⁿ / √n)

Reason:
- The algorithm generates only valid parentheses combinations.
- The total number of valid combinations is the nth Catalan number,
  which is approximately O(4ⁿ / √n).

💾 Space Complexity: O(n)

Reason:
- The recursion stack can grow up to 2n levels.
- Excluding the output list, the auxiliary space required is O(n).
*/