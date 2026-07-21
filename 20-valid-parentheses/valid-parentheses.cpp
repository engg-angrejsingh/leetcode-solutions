class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty())
                    return false;

                if ((c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '['))
                    return false;

                st.pop();
            }
        }

        return st.empty();
    }
};

/*
⏱️ Time Complexity: O(n)

Reason:
- We traverse the string once.
- Each bracket is pushed onto or popped from the stack at most one time.

💾 Space Complexity: O(n)

Reason:
- In the worst case, all opening brackets are stored in the stack.
- This requires O(n) auxiliary space.
*/