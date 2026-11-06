class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /**
            Description: Go in a spiral sequence

            Direction Sequence: Right ---> Down ---> Left ---> Up

            Boundary update:
            1. Right: top++
            2. Down: right--
            3. Left: bottom--
            4. Up: left++

            Continue update:
            1. top <= bottom, left <= right
        **/
        int row = matrix.size();
        int column = matrix[0].size();

        int top = 0;
        int bottom = row - 1;
        int left = 0;
        int right = column - 1;

        vector<int> result;

        while (top <= bottom && left <= right) {
            // right
            for (int j = left; j <= right; j++ ){
                result.push_back(matrix[top][j]);
            }
            
            top++;

            if (top > bottom){  // prevents duplicates
                break;
            }

            // down
            for (int i = top; i <= bottom; i++){
                result.push_back(matrix[i][right]);
            }

            right--;

            if (left > right){
                break;
            }

            // left
            for (int j = right; j >= left; j--){
                result.push_back(matrix[bottom][j]);
            }
            
            bottom--;

            // up
            for (int i = bottom; i >= top; i--){
                result.push_back(matrix[i][left]);
            }

            left++;
        }

        return result;

    }
};
