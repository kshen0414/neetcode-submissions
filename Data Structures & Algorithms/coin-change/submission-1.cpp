class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        /**
            Algorithm: 1D DP
            = dp[i]  ---> minimum # of coins needed to make amount i
            = dp[i] size depends on the amount
        **/
        int n = amount + 1;
        vector<int> dp(n, n);

        // Base case
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int j = 0; j < coins.size(); j++) {
                if (coins[j] <= i) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }

        if (dp[amount] == amount + 1) {
            return -1;
        } else {
            return dp[amount];
        }
    }
};
