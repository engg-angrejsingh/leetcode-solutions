class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();

        // Put every number x in position x-1
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 1 && nums[i] <= n &&
                   nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Find the first position containing the wrong value
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                return i + 1;
        }

        return n + 1;
    }
};

/*
⏱️ Time Complexity: O(n)

Reason:
- Each number is placed in its correct position using swaps.
- Although there is a nested while loop, each swap puts an element closer to its correct position.
- The final scan takes O(n).
- Overall complexity is O(n).

💾 Space Complexity: O(1)

Reason:
- The array is modified in-place.
- Only a few variables are used.
- No extra data structures are required.
*/