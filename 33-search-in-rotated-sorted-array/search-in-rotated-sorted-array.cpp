class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;

            // Left half is sorted
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }

        return -1;
    }
};

/*
⏱️ Time Complexity: O(log n)

Reason:
- We perform Binary Search on the array.
- In each iteration, the search space is reduced by half.
- Therefore, the total number of iterations is logarithmic.

💾 Space Complexity: O(1)

Reason:
- Only a few integer variables (left, right, and mid) are used.
- No extra data structures are required.
*/