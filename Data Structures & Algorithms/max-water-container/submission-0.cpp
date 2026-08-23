class Solution {
public:
    int maxArea(vector<int>& heights) {
        /**
            Also a two pointer problem, this time
            we want to maximize the area of the container
            To note, must make sure the water does not spill!
            
            approach:
            - choose 2 lines of i, j
                - height= min(height[i], height[j])
                - area = height x (j-i)
        **/
        // determine size of vector height
        int n = heights.size();
        int left=0;
        int right=n-1;
        int height, area, maxArea;

        while(left<right){
            height = min(heights[left], heights[right]);
            area = height*(right-left);
            maxArea= max(maxArea, area);
            
            // if the left wall is too short, we increment it to move right
            if(heights[left]<heights[right]){
                left++;
            }
            // or else right wall is too short, increment to move left
            else if(heights[right]<heights[left]){
                right--;
            }

            // if heights[left]==heights[right]
            else{
                right--;
                // left++ works too !!
            }
           
        }
        return maxArea;
    }
};
