class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            if (mp.count(complement)) {
                return {mp[complement], i};
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};

/*
Time Complexity: O(n)
- We traverse the array only once.
- Hash map insertion and lookup take O(1) on average.

Space Complexity: O(n)
- In the worst case, the hash map stores all elements.
*/