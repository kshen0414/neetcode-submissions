class Solution {
public:
    string longestPalindrome(string s) {
        /*
           Algorithm: 2D Dynamic Programming
         */

        int n = s.size();

        if (n == 0) {   // empty string
            return "";
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Track the longest palindrome
        int maxLen = 1;
        int start = 0;

        // Base Case 1: Single-character palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }

        // Base Case 2: Two-character palindromes
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;

                maxLen = 2;
                start = i;
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

                    // Update longest palindrome
                    if (len > maxLen) {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
