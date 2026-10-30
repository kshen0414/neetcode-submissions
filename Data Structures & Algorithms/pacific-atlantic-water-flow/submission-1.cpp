class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        /**
            Algo: Graph (DFS)

            Idea: Reverse DFS
            - Pacific: start from top row, left column
            - Atlantic: start from bottom row, right column
        **/
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        vector<vector<int>> result;

        // Pacific - top boundary
        for (int col = 0; col < cols; col++) {
            dfs(0, col, heights, pacific);
        }

        // Pacific - left boundary
        for (int row = 0; row < rows; row++) {
            dfs(row, 0, heights, pacific);
        }

        // Atlantic - bottom boundary
        for (int col = 0; col < cols; col++) {
            dfs(rows - 1, col, heights, atlantic);
        }

        // Atlantic - right boundary
        for (int row = 0; row < rows; row++) {
            dfs(row, cols - 1, heights, atlantic);
        }

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (pacific[row][col] && atlantic[row][col]) {
                    result.push_back({row, col});
                }
            }
        }

        return result;
    }

    void dfs(int row, int col, vector<vector<int>>& heights, vector<vector<bool>>& visited) {
        int rows = heights.size();
        int cols = heights[0].size();

        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return;
        }

        if (visited[row][col]) {
            return;
        }

        int currentHeight = heights[row][col];
        visited[row][col] = true;

        // move up
        if (row > 0 && heights[row - 1][col] >= currentHeight) {
            dfs(row - 1, col, heights, visited);
        }

        // move down
        if (row + 1 < rows && heights[row + 1][col] >= currentHeight) {
            dfs(row + 1, col, heights, visited);
        }

        // left
        if (col > 0 && heights[row][col - 1] >= currentHeight) {
            dfs(row, col - 1, heights, visited);
        }

        // right
        if (col + 1 < cols && heights[row][col + 1] >= currentHeight) {
            dfs(row, col + 1, heights, visited);
        }
    }
};
