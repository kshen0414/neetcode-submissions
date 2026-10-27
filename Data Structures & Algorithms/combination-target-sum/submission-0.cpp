class Solution {
   public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        /**
            Algorithm: Backtrack
            Visualisation:
            - Similar to DFS
            - We are building and traversing the invisible tree the same time
        **/
        int startIndex = 0;
        int currentSum = 0;

        vector<int> current;
        vector<vector<int>> result;

        backtrack(startIndex, currentSum, nums, target, current, result);
        return result;
    }

    // recursive helper
    void backtrack(int startIndex, int currentSum, vector<int>& nums, int target,
                   vector<int>& current, vector<vector<int>>& result) {
        // base case 1: currentSum == target
        if (currentSum == target) {
            result.push_back(current);
            return;
        }

        // base case 2: currentSum > target
        if (currentSum > target) {
            return;
        }

        // base case 3: currentSum < target
        for (int i = startIndex; i < nums.size(); i++) {
            current.push_back(nums[i]);
            backtrack(i, currentSum + nums[i], nums, target, current, result);
            current.pop_back();
        }
    }
};
