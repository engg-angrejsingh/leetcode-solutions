class Solution {
public:
    vector<vector<int>> dp;
    bool solve(int i, int j, string &s, string &p) {
        // If pattern is exhausted, string should also be exhausted
        if (j == p.size())
            return i == s.size();

        // Return already computed result
        if (dp[i][j] != -1)
            return dp[i][j];

        // Check if current characters match
        bool firstMatch = (i < s.size()) &&
                          (s[i] == p[j] || p[j] == '.');

        // If next character is '*'
        if (j + 1 < p.size() && p[j + 1] == '*') {

            // Option 1: Skip current character and '*'
            // Option 2: Use '*' to match one character and stay at same pattern
            return dp[i][j] =
                solve(i, j + 2, s, p) ||
                (firstMatch && solve(i + 1, j, s, p));
        }

        // Normal character match
        return dp[i][j] =
            firstMatch && solve(i + 1, j + 1, s, p);
    }

    bool isMatch(string s, string p) {

        int m = s.size();
        int n = p.size();

        // -1 means this state has not been computed yet
        dp.assign(m + 1, vector<int>(n + 1, -1));

        return solve(0, 0, s, p);
    }
};

/*
⏱️ Time Complexity: O(m × n)

📌 m = length of string s
📌 n = length of pattern p

💡 Why?
- There are (m + 1) × (n + 1) possible states (i, j).
- Each state is computed only once because of memoization.
- Each computation takes O(1).

📦 Space Complexity: O(m × n)

💡 Why?
- DP table stores all (i, j) states.
- Recursive call stack takes O(m + n) in the worst case.
*/