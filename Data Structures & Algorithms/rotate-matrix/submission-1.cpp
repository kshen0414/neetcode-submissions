class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /**
            Description:
            - rotate the n x n matrix of integers by 90 degrees
            - Don't allocate another 2D matrix

            Thought:
            - 1st row ---> last column
            - middle row ---> middle column
            - last row ---> 1st column
            - Determine # of layers, based on # of layers, do rotating
              - floor(n / 2)
              - # of elements outer layer / 4 = rotation operations
                - (4n - 4) / 4 = n - 1

            start = i
            end = n - 1 - i
        **/

        int n = matrix.size();


        for (int i = 0; i < n / 2; i++){  // layers

            for (int j = i; j < n - i - 1; j++){ // groups for 4 elements within layer
                // completes one 4 element rotation
                int temp = matrix[i][j];

                // bottom left to top
                matrix[i][j] = matrix[n - 1 - j][i];

                // bottom right to bottom left
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j] ;

                // top right to bottom right
                matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];

                // top left to top right
                matrix[j][n - 1 - i] = temp;

            }
        }

    }
};
