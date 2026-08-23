class Solution {
public:
    int getSum(int a, int b) {
        int carry;

        while (b!=0){
            // generate carry
            unsigned carry = a & b;

            // xor a,b and assign result into a
            a = a ^ b;

            // left shift carry and assign into b
            b = carry << 1;
        }

        return a;
    }
};