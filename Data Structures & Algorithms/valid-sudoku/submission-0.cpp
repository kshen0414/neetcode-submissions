class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // so i guess there are 3 conditions to fulfill
        // each row must contain the digits 1-9 without duplicate
        // each column must contain the digits 1-9 without duplicates
        // each of the nine 3x3 sub-boxes of the grid must contain the digits 1-9
           // without duplicates

        /**
            If condition 1, condition 2 and condition 3 contains duplicates, 
            then we return false
        **/

        // iterate row
        for(const auto& row : board){
            unordered_map<char,int> umap_r;

            for(const auto& element: row){
                char x = element;

                if(x=='.'){
                    continue;
                }

                if(umap_r.find(x) != umap_r.end()){
                    return false;
                }
                umap_r[x]++;
            }
        }

        // iterate column
        for(int col=0; col<9; col++){
            unordered_map<char,int> umap_c;

            for(int row=0; row<9; row++){
                char x = board[row][col];

                if(x=='.'){
                    continue;
                }

                if(umap_c.find(x) != umap_c.end()){
                    return false;
                }
                umap_c[x]++;
            }
        }

        // iterate 3x3 sub-boxes
        for(int box = 0; box < 9; box++){
            unordered_map<char,int> umap_3x3;
            
            // Calculate starting row and column for this box
            int start_row = (box / 3) * 3;  // 0,0,0,3,3,3,6,6,6
            int start_col = (box % 3) * 3;  // 0,3,6,0,3,6,0,3,6
            
            // Now iterate through the 3x3 area
            for(int row = start_row; row < start_row + 3; row++){
                for(int col = start_col; col < start_col + 3; col++){
                    char x = board[row][col];
                    
                    // Your same duplicate checking logic here
                    if(x == '.') continue;
                    
                    if(umap_3x3.find(x) != umap_3x3.end()){
                        return false;
                    }
                    umap_3x3[x]++;
                }
            }
        }

        return true;
    }
};
