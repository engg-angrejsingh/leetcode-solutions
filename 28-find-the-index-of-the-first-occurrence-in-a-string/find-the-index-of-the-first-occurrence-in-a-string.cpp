class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        for (int i = 0; i <= n - m; i++) {
            int j = 0;
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }
            if (j == m) return i;
        }

        return -1;
    }
};

/*
⏱️ Time Complexity: O((n - m + 1) × m)

Reason:
- n is the length of `haystack` and m is the length of `needle`.
- For each possible starting position, we may compare up to m characters.
- In the worst case, this results in O((n - m + 1) × m), which is commonly written as O(n × m).

💾 Space Complexity: O(1)

Reason:
- Only a few integer variables are used.
- No extra data structures are required.
*/