class Solution {
public:
    int rob(vector<int>& nums) {
        /**
            Algorithm:
            - DP + Memoization
            - Can use brute force or greedy but is not optimal
        **/
        int n = nums.size();

        if (n < 2){  // only single element
            return nums[0];
        }

        vector<int> dp(n, 0);

        // memoize max loots for first 2 indexes
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++){
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }

        return dp[n - 1];   // return last element
    }
};
