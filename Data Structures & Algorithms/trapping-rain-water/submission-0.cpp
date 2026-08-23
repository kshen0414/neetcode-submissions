class Solution {
public:
    int trap(vector<int>& height) {
        /**
            To note, height[i] represents the height of a bar
            Whereas each bar has a width of 1
        **/
        int n = height.size();
        int left = 0, right = n-1;
        int res = 0;
        int maxLeft = height[left], maxRight = height[right];

        while(left<right){
            if(maxLeft < maxRight){
                left++;
                maxLeft = max(maxLeft, height[left]);
                res += maxLeft - height[left];
            }

            else{
                right--;
                maxRight = max(maxRight, height[right]);
                res += maxRight - height[right];
            }
        }

        return res;
    }
};
