class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /**
            Algo: Bit Man

            Description: Use XOR
        **/
        int n = nums.size();
        int miss = n;

        for (int i = 0; i < n; i++){
            miss ^= nums[i];
            miss ^= i;
        }

        return miss;
    }
};
