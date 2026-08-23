class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        
        // declare an unordered_set
        unordered_set<int> hashset(nums.begin(), nums.end());;

        // declare size of vector
        int n = nums.size();

        // insert all vector values into hash set
        // iterate hash set, if hash has duplicate value, then return false

        // syntax for contructing the unordered set from a vector
        // std::vector<int> v;
        // std::unordered_set<int> s(v.begin(), v.end());

        // hashset(nums.begin(), nums.end());

        // help from gpt
        if(nums.size()>hashset.size()){
            return true;
        }
        else{
            return false;
        }
        

    }
};