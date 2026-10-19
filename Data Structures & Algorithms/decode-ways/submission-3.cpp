class Solution {
public:
    int numDecodings(string s) {
        /**
            Algorithm:
            - 1D dp
            - dp[i] represents the # of ways to decode the first i characters
            - dp[i] = dp[i - 1] + dp[i - 2]
            
            1. dp[i - 1]: when final single digit is (1 - 9)
            2. dp[i - 2]: when final two digits form a valid number (10 - 26)
        **/

        int n = s.size();

        vector<int> dp(n + 1, 0);

        dp[0] = 1;  // empty string

        // check for '0'
        if(s[0] != '0'){
            dp[1] = 1;
        }
        else{
            dp[1] = 0;
        }

        for (int i = 2; i <=n; i++){
            // final single digit
            if (s[i - 1] >= '1' && s[i - 1] <= '9'){
                dp[i] += dp[i - 1];
            }

            // final 2 digits
            int num = stoi(s.substr(i - 2, 2));
            if (num >= 10 && num <= 26){
                dp[i] += dp[i - 2];
            }
        }
        return dp[n];
    }
};
