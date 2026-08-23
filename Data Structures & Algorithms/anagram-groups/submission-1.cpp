class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> umap;  // declaring our hashmap to store key-value pairs
        vector<vector<string>> res;  // our nested vector to store the result

        for(string s: strs){
            string sSorted = s;
            sort(sSorted.begin(), sSorted.end());
            umap[sSorted].push_back(s);
        }

        for(auto &x: umap){
            // res.push_back(x.second);

            // optionally, for better performance
            res.push_back(move(x.second));

        }

        return res;
    }
};
