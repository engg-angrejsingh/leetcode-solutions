class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Find the first decreasing element from the right
        int i = n - 2;
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        // Step 2: Find the next greater element and swap
        if (i >= 0) {
            int j = n - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            swap(nums[i], nums[j]);
        }

        // Step 3: Reverse the suffix
        reverse(nums.begin() + i + 1, nums.end());
    }
};

/*
⏱️ Time Complexity: O(n)

Reason:
- We scan the array from right to left to find the pivot.
- We scan again from the right to find the next greater element.
- Finally, we reverse the suffix of the array.
- Each step takes linear time, resulting in an overall complexity of O(n).

💾 Space Complexity: O(1)

Reason:
- The permutation is modified in-place.
- Only a few extra variables are used.
*/