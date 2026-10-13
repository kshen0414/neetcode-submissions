class Solution {
public:
    int rob(vector<int>& nums) {
        /**
            Algorithm: DP

            Solution: Convert to Linear Arrangement

            Scenario A
            - first house, up to n - 1 house

            Scenario B
            - 2nd house, up to nth house
        **/

        int n = nums.size();

        // single house
        if (n == 1){
            return nums[0];
        }

        return max(dpHelper(nums, 0, n - 2), dpHelper(nums, 1, n - 1));  // return the max of scenarioA, scenarioB

    }

    int dpHelper(vector<int> &nums, int start, int end){
        int n = end - start + 1;
        vector<int> dp(n, 0);  // initialize vector with n '0s'

        if (n == 1){
            return nums[start];
        }

        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);

        for (int i = 2; i < n; i++){
            dp[i] = max(dp[i - 2] + nums[start + i], dp[i - 1]);
        }

        return dp[n - 1];

    }
};
