class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {

        int n = nums.size();

        // Sort the array to apply the two pointers approach
        sort(nums.begin(), nums.end());

        // Initialize with the first possible triplet
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int k = 0; k < n - 2; k++) {

            int left = k + 1;
            int right = n - 1;

            while (left < right) {

                int currentSum = nums[k] + nums[left] + nums[right];

                // Update the closest sum if current sum is nearer to the target
                if (abs(target - currentSum) < abs(target - closestSum)) {
                    closestSum = currentSum;
                }

                if (currentSum < target) {
                    left++;
                }
                else if (currentSum > target) {
                    right--;
                }
                else {
                    // Exact target found
                    return currentSum;
                }
            }
        }

        return closestSum;
    }
};

/*
⏱️ Time Complexity: O(n²)

Reason:
- Sorting takes O(n log n).
- For each element, two pointers scan the remaining array.
- Overall complexity is O(n²).

💾 Space Complexity: O(1)

Reason:
- Only a few extra variables are used.
- No additional data structures are required.
*/