class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        // calculate the size of vector nums
        int n = nums.size();

        // using the approach on unordered_map
        unordered_map<int, int> umap;

        for(int i=0; i<n; i++){
            int x = nums[i];

            if(umap.find(x)!=umap.end()){   // check if the key duplicates
                return true;
            }
            
            // umap[x]++;
            umap[nums[i]] = true;
        }

        return false;
    }
};