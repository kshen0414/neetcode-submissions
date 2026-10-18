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
        
        // from 1 to amount
        for (int i = 1; i <= amount; i++) {
            // try every coin denomination
            for (int j = 0; j < coins.size(); j++) {
                // select coins that do not exceed current amount
                if (coins[j] <= i) {
                    // current best, remainder coins + selected coin
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1); 
                }
            }
        }

        // invalid case
        if (dp[amount] == n) {
            return -1;
        } else {
            return dp[amount];
        }
    }
};
