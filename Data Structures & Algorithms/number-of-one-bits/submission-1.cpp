class Solution {
public:
    int hammingWeight(uint32_t n) {
        /**
            Algo: Bit Manipulation

            Other answers:
            - https://www.geeksforgeeks.org/c/counting-set-bit-in-c/#method-2-using-brian-kernighans-algorithm
        **/
        int count = 0;
        for (int i = 0; i < 32; i++){
            // every time i increases by 1, the '1' bit moves one position to left
            int setbit = 1 << i;  

            if ((setbit & n) > 0){  
                // only increment when both ith set bit position and ith n bit position are both 1 after &
                count++;
            }
        }

        return count;
    }
};
