class Solution {
   public:
    int findMin(vector<int>& nums) {
        /*
            Algorithm:
            - Need to find the minimum element in an array
            - From what we observe, the pivot is the minimum element
            - The pivot separates the first and 2nd half of the array
        */
        int low = 0;
        int high = nums.size() - 1;
        int n = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (foundPivot(nums, mid, n)) {
                // high = mid - 1;
                low = mid + 1;
            }

            else {
                // low = mid + 1;
                high = mid - 1;
            }
        }

        return nums[low];
    }

    // our own custom api called when we found the pivot
    int foundPivot(vector <int> &nums, int mid, int last) {
        if (nums[mid] > nums[last]) {
            return true;
        } else {
            return false;
        }
    }
};
