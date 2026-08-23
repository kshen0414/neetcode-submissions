class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
            Profit = Sell Price - Buy Price
            Main Solution:
                - Use Sliding Window
        */

        /*
            Alternative solution is using Dynamic Programming
            or
            Greedy Solution
        */

        int L = 0;
        int R = 1;
        int maxProfit = 0;

        while (R < prices.size()){
            if(prices[R] - prices[L] > 0){
                maxProfit = max(maxProfit, prices[R] - prices[L]);
            }

            else{
                L = R;  // if negative profit, then we move the Left Pointer
            }
            R++;  // increment Right Pointer
        }

        return maxProfit;

    }
};
