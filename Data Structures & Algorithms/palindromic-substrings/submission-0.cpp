class Solution {
public:
    int countSubstrings(string s) {
        /**
            Algorithm: 2D dp

            Input samples:
            1. 'aba': 'a', 'b', 'a', 'aba'

            Notes that:
            1. substring: characters must be contiguous
            2. subsequence: characters can be skipped
        **/
        int n = s.size();
        int count = 0;

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Base Case 1: Single-character palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            count++;
        }

        // Base Case 2: Two-character palindromes
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                count++;
            }
        }

        // Check substrings of length 3 or greater
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {

                // Ending index of current substring
                int j = i + (len - 1);

                // Check outer characters and inner substring
                if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {

                    dp[i][j] = 1;
                    count++;
                }
            }
        }

        return count;

    }
};
