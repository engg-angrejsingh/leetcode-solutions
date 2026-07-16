class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> result;
        int n = nums.size();

        // Sort the array to use the two pointers approach
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            // Skip duplicate values for the first element
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right) {

                int currentSum = nums[i] + nums[left] + nums[right];

                if (currentSum < 0) {
                    left++;
                }
                else if (currentSum > 0) {
                    right--;
                }
                else {

                    // Found a valid triplet
                    result.push_back({nums[i], nums[left], nums[right]});

                    left++;
                    right--;

                    // Skip duplicate values
                    while (left < right && nums[left] == nums[left - 1])
                        left++;

                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }

        return result;
    }
};

/*
⏱️ Time Complexity: O(n²)

Reason:
- Sorting the array takes O(n log n).
- For each element, we use two pointers to scan the remaining array.
- Overall complexity is O(n²).

💾 Space Complexity: O(1)

Reason:
- We only use a few extra variables.
- The returned result is not counted as extra space.
*/