class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /**
            Description:
            - for an m x n matrix of integers
            - if an element is 0
            - set its entire row and column to 0's
            - since the return type is void, we have to modify the vector in place
        **/

        // hash set to track state
        unordered_set<int> row_state;
        unordered_set<int> column_state;
        
        for (int i = 0; i < matrix.size(); i++){  // rows
            for (int j = 0; j < matrix[0].size(); j++){  // columns
                // row state, column track
                if(matrix[i][j] == 0){
                    row_state.insert(i);
                    column_state.insert(j);
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++){  // rows
            for (int j = 0; j < matrix[0].size(); j++){  // columns
                // set row, column to 0
                if(row_state.count(i) || column_state.count(j)){
                    matrix[i][j] = 0;
                }

            }
        }
        
    }
};
