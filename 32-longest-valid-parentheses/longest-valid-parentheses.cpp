class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();

                if (st.empty()) {
                    st.push(i);
                } else {
                    ans = max(ans, i - st.top());
                }
            }
        }

        return ans;
    }
};

/*
⏱️ Time Complexity: O(n)

Reason:
- We traverse the string only once.
- Each index is pushed onto and popped from the stack at most one time.

💾 Space Complexity: O(n)

Reason:
- In the worst case, the stack stores all indices of the characters.
- Therefore, the auxiliary space required is O(n).
*/