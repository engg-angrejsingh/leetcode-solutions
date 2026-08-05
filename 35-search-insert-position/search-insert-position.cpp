class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        // Target not found, left is the correct insertion index
        return left;
    }
};

/*
⏱️ Time Complexity: O(log n)

Reason:
- We use Binary Search on the sorted array.
- In each iteration, the search space is reduced by half.
- Therefore, the overall time complexity is O(log n).

💾 Space Complexity: O(1)

Reason:
- Only a few integer variables (left, right, and mid) are used.
- No extra data structures are required.
*/