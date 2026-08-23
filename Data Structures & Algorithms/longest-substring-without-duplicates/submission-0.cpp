class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /**
            Algorithm:
                - use sliding window technique
                - and hashset to check if character has repeated
        **/

        int Left = 0;
        int maxLength = 0;
        unordered_set<char> ust = {};
        int n = s.size();
        int currentLength;

        for(int i=0; i<n; i++){

            while (ust.find(s[i]) != ust.end())  {
                ust.erase(s[Left]);
                Left++;
            }

            ust.insert(s[i]);

            currentLength = i - Left + 1;
            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
        
    }
};
