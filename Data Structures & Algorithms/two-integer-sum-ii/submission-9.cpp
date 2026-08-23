class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /**
            Notes:
            - non-decreasing order means that index[n] < index[n+1],
              where n=0,1,2, ... and also means that it is a sorted array
            - index1 != index2
        **/
        int n = numbers.size();  //getting the size of the vector
        int start=0;
        int end=n-1;

        // iterate the vector of numbers
        while(start<=end){
            if(start!=end && (numbers[start]+numbers[end]==target)){
                return{start+1,end+1};
            }

            // the idea behind start pointer + end pointer > target
            // is that right side element would always be larger than left side
            // end value is too big, we want to reduce the total
            // hence end--, we want to choose a smaller number
            // start++, wouldn't make sense because we are creating an even larger total

            if(numbers[start]+numbers[end]>target){
                end--;
            }
            
            // else if total is smaller than target
            // we choose a larger start number
            else{
                start++;
            }
        }
        return {};  // invalid result
    }
};
