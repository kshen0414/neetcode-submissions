class Solution {
   public:
    int characterReplacement(string s, int k) {
        /*
            Algorithm:
            - Sliding Window Algorithm
            - Hashmap to track frequency

            test case 1: equal frequency
            test case 2: one character occurs more often

            References: https://www.w3schools.com/cpp/cpp_maps.asp
        */
        int left = 0, right = 0;
        int n = s.size();
        int maxLength = 0;
        unordered_map<char, int> umap;

        while (right < n) {
            int maxFrequency = 0;
            int windowSize;
            int replacementsNeeded;
            
            // expand window
            // if current character does not exist in the hashmap
            // add it and increment frequency counter by 1
            umap[s[right]]++;

            for (auto pair : umap) {
                maxFrequency =
                    max(maxFrequency, pair.second);  // get the highest frequency of value
            }

            // for (auto it = umap.begin(); it != umap.end(); it++) {
            //     int frequency = it->second;
            // }

            windowSize = right - left + 1;
            replacementsNeeded = windowSize - maxFrequency;

            // another while loop to shrink the window

            while (replacementsNeeded > k) {
                umap[s[left]]--;
                left++;
                maxFrequency = 0;

                for (auto pair : umap) {
                    maxFrequency = max(maxFrequency, pair.second);  
                    // get the highest frequency of value
                }

                windowSize = right - left + 1;
                replacementsNeeded = windowSize - maxFrequency;
            }

            maxLength = max(maxLength, right - left + 1);
            right++;
        }

        return maxLength;
    }
};
