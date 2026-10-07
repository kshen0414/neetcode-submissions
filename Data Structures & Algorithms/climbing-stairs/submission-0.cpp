class Solution {
public:
    int climbStairs(int n) {
        /**
            Algorithm:
            - Need to use DP
            - n represents the # of steps needed to climb up the stairs
            - can either take 1 or 2 steps
            - use dp array

            Observation:
            1. when n == 1 ---> 1 possible way (1 one step)
            2. when n == 2 ---> 2 possible ways (2 one steps, 1 two step)
            3. recursion is not an optimal solution for large n
        **/

        if (n == 1){
            return 1;
        }

        if (n == 2){
            return 2;
        }

        vector<int> dp(n, 0);  // initialize dp vector with 0's
        dp[0] = 1;
        dp[1] = 2;

        for (int i = 2; i < n; i++){   // start calculating from 3rd element
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n-1];
    }
};