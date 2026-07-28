class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

/*
⏱️ Time Complexity: O(n)

Reason:
- We traverse the array only once.
- Each element is checked exactly one time.

💾 Space Complexity: O(1)

Reason:
- The array is modified in-place.
- Only one extra variable (`k`) is used.
*/