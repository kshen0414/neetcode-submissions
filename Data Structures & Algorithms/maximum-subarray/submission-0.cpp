class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /**
            Algo: Kadane's Algo (Greedy Approach)
            Definition: subarray is a contiguous non-empty sequence of elements within an array

            Idea:
            1. track currentSum, maxSum
        **/
        int currentSum = nums[0];
        int maxSum = nums[0];

        // edge case: single element in nums vector
        if (nums.size() < 2){
            return nums[0];
        }

        // normal case: > 1 element
        for (int i = 1; i < nums.size(); i++){
            currentSum = max(currentSum + nums[i], nums[i]);
            maxSum = max(currentSum, maxSum);
        }

        return maxSum;
    }
};
