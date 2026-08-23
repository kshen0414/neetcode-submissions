class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;

        while(low<=high){
            int mid = (low+high)/2;

            // best case: target is in the middle
            if(target==nums[mid]){
                return mid;
            }

            // 2nd case: target>mid
            else if(target>nums[mid]){
                low = mid+1;
            }

            // 3rd case: target<mid
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};
