class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        /**
                    0 1 2 3
            nums = [1,2,4,6]

                      0  1  2  3
            output = [48,24,12,8]

            whereby output[i] is the product of all elements in nums
            except nums[i]

            Ex: if output[0] = 48
                nums[1]*nums[2]*nums[3]=48

            i. input
             - elements from nums vector
            ii.what to do with input
             - iterate through nums vector, and multiply from start to finish
               except its own index
            iii. output
             - a vector with new elements based off multiplication
             - i guess can use push_back
        **/

        int n = nums.size();
        // int product=1;
        vector<int> out;

        for(size_t i=0; i<n; i++){
        int product=1;
            for(size_t j=0; j<n; j++){
                if(i==j){
                    continue;
                }
                else{
                    product *= nums[j];
                    // out.push_back(product);
                }
            }
            out.push_back(product);
        }
        return out;
    }
};
