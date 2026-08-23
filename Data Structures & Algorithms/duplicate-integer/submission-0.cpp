class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // brute force solution, to check every combination
        int count =0;

        int n = nums.size();  // get the size of vector

        for(int i=0; i<n;i++){
            int count = 1; // resets the count for every new num
            
            for(int j=0; j<n; j++){
                
                if(i!=j && nums[i]==nums[j] ){  // skip if i==j
                    count++;
                }
            }

            if(count>1){
                return true;
            }

            
        }
        
        
        return false;
        

        
        // return true if appear > 1

        // else return false

    }
};
