class Solution {
public:
    string minWindow(string s, string t) {
    /**
        Algo: Sliding Window
    **/
    
    unordered_map<char, int> mapT;
    unordered_map<char, int> mapS;

    // count required characters in t
    for (char c : t){
        mapT[c]++;
    }

    int start = 0;
    int count = 0;
    string result = "";

    // expand window (right pointer)
    for (int i = 0; i < s.size(); i++){
        char c = s[i];

        if (mapT[c] > 0){
            mapS[c]++;

            if (mapT[c] >= mapS[c]){
                count++;
            }
        }

        // all required characters are present
        if (count == t.size()){
            // shrink the window (left pointer)

            while (mapT[s[start]] < mapS[s[start]] || mapT[s[start]] == 0){
                if (mapT[s[start]] < mapS[s[start]]){
                    mapS[s[start]]--;
                }

                start++;
            }

            // update shortest substring
            if (result.empty() || i - start + 1 < result.size()){
                result = s.substr(start, i - start + 1);
            }

        }
    }

    return result;

    }
};
