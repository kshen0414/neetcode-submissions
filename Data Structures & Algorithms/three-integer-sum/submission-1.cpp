class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /**
            Distinct means that after sorting the elements
            The values corresponding should not be the same
            as another triplet
        **/
        int n = nums.size();
        if(n==0 || n<3){
            return {};
        }
        
        set<vector<int>> s; // set will only store unique elements
        sort(nums.begin(), nums.end()); // using built in sort algorithm

        // triple nested for loop for brute force solution
        for(int i=0; i<n-2;i++){
            for(int j=i+1; j<n-1; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i]+nums[j]+nums[k]==0){
                        s.insert({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        // insert all unique triplets in result vector
        vector<vector<int>> ans(s.begin(), s.end());
        return ans;
    }
};
