class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0;

        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};


/*
⏱️ Time Complexity: O(n)

Reason:
- We traverse the array only once.
- Each element is compared and processed exactly one time.

💾 Space Complexity: O(1)

Reason:
- The array is modified in-place.
- Only two pointer variables are used.
*/