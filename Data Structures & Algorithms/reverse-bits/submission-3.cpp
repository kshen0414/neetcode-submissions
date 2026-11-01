class Solution {
   public:
    uint32_t reverseBits(uint32_t n) {
        /**
            Algo: Bit Manipulation

            Description:
            1. First setbit, creates a mask to check if original bit at position i is 1
            2. Second newSetbit, creates a mask to place a 1 at reversed position
        **/

        int newPos;
        int reversed = 0;
        for (int i = 0; i < 32; i++) {
            int setbit = 1 << i;

            if (setbit & n) {
                newPos = 31 - i;
                int newSetbit = 1 << newPos;

                reversed = reversed | newSetbit;
            }
        }

        return reversed;
    }
};
