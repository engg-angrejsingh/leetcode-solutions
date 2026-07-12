class Solution {
public:
    int maxArea(vector<int>& height) {

        int maximumWater = 0;

        int left = 0;
        int right = height.size() - 1;

        while (left < right) {

            // Distance between the two lines
            int width = right - left;

            // Water level is limited by the shorter line
            int currentHeight = min(height[left], height[right]);

            // Calculate the current container area
            int currentWater = width * currentHeight;

            // Update the maximum water found so far
            maximumWater = max(maximumWater, currentWater);

            // Move the pointer pointing to the shorter line
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return maximumWater;
    }
};

/*
⏱️ Time Complexity: O(n)

Reason:
- Both pointers move toward each other.
- Each element is visited at most once.
- Therefore, the total number of operations is linear.

💾 Space Complexity: O(1)

Reason:
- Only a few integer variables are used.
- No extra data structures are created.
- The space remains constant regardless of input size.
*/