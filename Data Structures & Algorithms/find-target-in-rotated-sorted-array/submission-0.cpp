class Solution {
public:
    int search(vector<int>& nums, int target) {
        /*
        Let's try the trivial solution of single for loop one pass
        */

        int n = nums.size();

        for(int i = 0; i < n; i++){
            if(nums[i] == target){
                return i;
            }
        
        }
        
        return -1;

    }
};
