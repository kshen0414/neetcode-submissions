class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        for (int i = 0; i < 32; i++){
            int setbit = 1 << i;

            if ((setbit & n) > 0){
                count++;
            }
        }

        return count;
    }
};
