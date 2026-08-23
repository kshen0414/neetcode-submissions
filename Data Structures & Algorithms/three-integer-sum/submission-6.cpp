class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /**
            Distinct means that after sorting the elements
            The values corresponding should not be the same
            as another triplet

            This time, let's implement an optimal solution
            which is O(n^2) instead of O(n^3)
        **/
        vector<vector<int>> res; // to store the result of the correct triplets

        // sort the original nums vector, to detect duplicates
        sort(nums.begin(), nums.end());

        // declare size of vector
        int n = nums.size();

        // set a main for loop to iterate nums vector
        for(int i=0; i<n; i++){

            // to check for duplicates with the previous element
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }

            // declare start and end pointer
            int j = i+1;
            int k = nums.size()-1;

            while(j<k){
                int total = nums[i]+nums[j]+nums[k];

                if(total>0){
                    k--;  // right pointer
                }
                else if(total<0){
                    j++;  // left pointer
                }
                else{ // equal to 0
                    res.push_back({nums[i], nums[j], nums[k]});
                    j++;  // left pointer moves 1 step to the right
                    k--;

                    while(nums[j]==nums[j-1] && j<k){
                        j++;
                    }
                    while (j < k && nums[k] == nums[k+1]) {
                        k--;
                    }
                }
                
            }
        }
        return res;
    }
};
