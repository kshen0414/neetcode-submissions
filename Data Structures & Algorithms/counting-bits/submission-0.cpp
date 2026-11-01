class Solution {
   public:
    vector<int> countBits(int n) {
        /**
            Algo: Bit Manipulation
        **/
        vector<int> result;

        for (int i = 0; i <= n; i++) {
            int count = 0;
            for (int j = 0; j < 32; j++) {
                int setbit = 1 << j;

                if ((setbit & i) > 0) {
                    count++;
                }
            }
            result.push_back(count);
        }

        return result;
    }
};
