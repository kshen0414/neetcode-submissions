class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        /**
            Notes:
            - non-decreasing order means that index[n] < index[n+1],
              where n=0,1,2, ...
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
            
            if(numbers[start]+numbers[end]>target){
                end--;
            }
            else{
                start++;
            }
            
        }
        return {-1,-1};
    }
};
