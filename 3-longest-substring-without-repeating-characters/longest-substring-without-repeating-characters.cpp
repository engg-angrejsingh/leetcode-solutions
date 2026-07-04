class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        vector<int> hash(256, -1);

        int left = 0;
        int right = 0;

        int maxLen = 0;
        int n = s.size();

        while (right < n) {

        
            if (hash[s[right]] != -1 && hash[s[right]] >= left) {
                left = hash[s[right]] + 1;
            }

            hash[s[right]] = right;

            maxLen = max(maxLen, right - left + 1);

            right++;
        }

        return maxLen;
    }
};

/*
Time Complexity: O(n)

Reason:
- We traverse the string only once.
- Each character is processed exactly one time.
- The left pointer only moves forward and never moves backward.

Space Complexity: O(1)

Reason:
- We use a fixed-size array of 256 elements to store
  the last seen index of each ASCII character.
- Since the array size is constant, the extra space
  does not depend on the input size.
*/