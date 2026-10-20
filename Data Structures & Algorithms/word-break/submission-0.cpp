class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /**
            Algorithm: 1D dp
            dp[i] = whether the first i characters can be split into valid dictionary words

            dp[j] = true, s[j:i] after the split must exist in wordDict
        **/

        int n = s.size();

        vector<bool> dp(n + 1, false);
        dp[0] = true;

        unordered_set<string> us(wordDict.begin(), wordDict.end());

        for (int i = 1; i <=n; i++){
            for (int j = 0; j < i; j++){
                if(dp[j] && us.count(s.substr(j, i - j))){
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};
