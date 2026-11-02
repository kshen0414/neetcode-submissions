class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        /**
            Algo: 2D DP

            Description:
            - A subsequence preserves the original character order, but characters don't have to be
        adjacent
            - A substring must be continuous (adjacent)

            dp[i][j] = len of LCS between first i and j characters

            Characters - Don't Match
            1. dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            ----> dp[i - 1][j]  skip the last character of text1
            ----> dp[i][j - 1]  skip the last character of text2

            Characters - Match
            2. dp[i][j] = dp[i - 1][j - 1] + 1;
            ---->  i - 1 to exclude last matched character from text1
            ---->  j - 1 to exclude last matched character from text2
            ---->  +1 count matching charcter found
        **/

        vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));  // + 1 for empty string

        // base case: string is empty, LCS length is 0...do nothing !

        // nested for loop
        for (int i = 1; i <=text1.size(); i++){
            for (int j = 1; j <= text2.size(); j++){
                if (text1[i - 1] == text2[j - 1]){  // match
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{ // don't match
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        return dp[text1.size()][text2.size()];

    }
};
