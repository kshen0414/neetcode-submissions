class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        /**
            Algo: Graphs

            Constraints:
            - The formation of an island is either through vertial or horizontal
            - Cannot be diagonal

        **/
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int islandCount = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if(grid[row][col] == '1' && !visited[row][col]){
                    islandCount++;
                    dfs(row, col, grid, visited);
                }
            }
        }

        return islandCount;
    }

    void dfs(int row, int col, vector<vector<char>> &grid,vector<vector<bool>> &visited ) {
        int rows = grid.size();
        int cols = grid[0].size();

        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return;
        }


        // if cell contains water or have already visited
        if(grid[row][col] == '0' || visited[row][col]){
            return;

        }

        // set visited to true
        visited[row][col] = true;

        // up
        dfs(row - 1, col, grid, visited);
        
        // down
        dfs(row + 1, col, grid, visited);
        
        // left
        dfs(row, col - 1, grid, visited);
        
        // right
        dfs(row, col + 1, grid, visited);


        return;
    }
};
