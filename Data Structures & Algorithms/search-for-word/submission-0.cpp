class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        /**
            Algo: Backtrack

            Contraints: Cannot reuse a cell
        **/
        int rows = board.size();
        int cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (dfs(row, col, 0, board, word, visited)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(int row, int col, int index, vector<vector<char>>& board, const string& word,
             vector<vector<bool>>& visited) {
        int rows = board.size();
        int cols = board[0].size();
        // base case 1: Entire word matched
        if (index == word.size()) {
            return true;
        }

        // base case 2: out of bounds
        if (row < 0 || row >= rows || col < 0 || col >= cols) {
            return false;
        }

        // base case 3: character mismatch
        if (board[row][col] != word[index]) {
            return false;
        }

        if(visited[row][col]){
            return false;
        }

        visited[row][col] = true;
        

        bool found = dfs(row - 1, col, index + 1, board, word, visited) ||
                     dfs(row + 1, col, index + 1, board, word, visited) ||
                     dfs(row, col - 1, index + 1, board, word, visited) ||
                     dfs(row, col + 1, index + 1, board, word, visited);

        visited[row][col] = false;
        return found;
    }
};
