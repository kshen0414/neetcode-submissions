class Solution {
public:
    int maxProduct(vector<int>& nums) {
        /**
            Algorithm: 1D dp

            Alternatively: Kandane's Algorithm
        **/
        int n = nums.size();

        int maxProduct = nums[0];
        int minProduct = nums[0];
        int result = nums[0];

        for (int i = 1; i < n; i++){
            int tempMaxProduct = maxProduct;
            int tempMinProduct = minProduct;

            maxProduct = max({nums[i] * tempMinProduct, nums[i] * tempMaxProduct, nums[i]});
            minProduct = min({nums[i] * tempMinProduct, nums[i] * tempMaxProduct, nums[i]});

            result = max(maxProduct, result);
        }

        return result;
    }
};
