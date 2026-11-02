class Solution {
public:
    int uniquePaths(int m, int n) {
        /**
            Algorithm: 2D dp

            Description:
            - m is the # of rows
            - n is the # of columns
            - Robot can only move either down or to the right at any point any time

            dp[i][j] = # of unique paths to reach cell (i, j)

            Recurrence:
            - dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
        **/

        vector<vector<int>> dp(m, vector<int>(n, 0));  // create 2D dp table

        // base case: first row, first column
        for (int j = 0; j < n; j++){  // first row, all columns
            dp[0][j] = 1;
        }

        for (int i = 0; i < m; i++){  // first column, all rows
            dp[i][0] = 1;
        }

        // nested for loop for remaining dp states
        for (int i = 1; i < m; i++){
            for (int j = 1; j < n; j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }

        return dp[m - 1][n - 1];

    }
};
