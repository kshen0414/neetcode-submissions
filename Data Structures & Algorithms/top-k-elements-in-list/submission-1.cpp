class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // nums is our vector int
        // k is our int

        int n = nums.size(); // size of vector

        sort(nums.begin(), nums.end()); // sorting the vector in ascending order

        // create an unordered map to keep track of # frequency
        unordered_map<int, int> um; // to note, we cannot sort it directly

        // calculate frequency of each element of vector
        for (auto i: nums){
            um[i]++;
        }

        // creating a vector of pairs
        vector<pair<int,int>> v;
        
        for (auto& entry : um) {
            v.push_back({entry.first, entry.second});
        }

        // sort the vector of pairs
        sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>&b){
            return a.second > b.second;
        });

        // store sorted vector of pairs
        vector<int> result;
        for (int i=0; i<k; ++i){
            result.push_back(v[i].first);
        }

        return result;
    }
};
