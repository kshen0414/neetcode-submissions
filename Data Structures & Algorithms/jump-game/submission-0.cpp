class Solution {
public:
    bool canJump(vector<int>& nums) {
        /**
            Algo: Greedy

            Description: nums[i] represents the max jump length
        **/
        int maxReach = nums[0];

        // edge case: single element
        if (nums.size() < 2){
            return true;
        }

        for(int i = 1; i < nums.size(); i++){
            if (i > maxReach){
                return false;
            }

            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};
