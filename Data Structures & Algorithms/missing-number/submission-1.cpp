class Solution {
public:
    int missingNumber(vector<int>& nums) {
        /**
            Algo: Bit Man

            Description: Use XOR

            XOR cancels two identical numbers
            - 3 ^ 3 = 0
            - 2 ^ 2 = 0
            - 1 ^ 1 = 0
        **/
        int n = nums.size();
        int miss = n;

        for (int i = 0; i < n; i++){
            miss ^= i;  // expected numbers
            miss ^= nums[i];  // actual numbers
        }

        return miss;
    }
};
