class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void solve(int idx, vector<int>& candidates, int target) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < candidates.size(); i++) {

            // Skip duplicate elements at the same recursion level
            if (i > idx && candidates[i] == candidates[i - 1])
                continue;

            if (candidates[i] > target)
                break;

            temp.push_back(candidates[i]);
            solve(i + 1, candidates, target - candidates[i]); // use next index
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        solve(0, candidates, target);
        return ans;
    }
};

/*
⏱️ Time Complexity: O(2ⁿ)

Reason:
- Each candidate can either be included or excluded, leading to a recursive search.
- In the worst case, all possible subsets are explored.
- Sorting the array takes O(n log n), which is dominated by the backtracking.

💾 Space Complexity: O(n)

Reason:
- The recursion stack and temporary combination vector can grow up to n elements.
- The output list is not included in the auxiliary space complexity.
*/