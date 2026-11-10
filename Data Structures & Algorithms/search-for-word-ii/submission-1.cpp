class Solution {
public:
    struct TrieNode {
        TrieNode* children[26] = {};
        string word = "";
    };

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& result){
        int rows = board.size();
        int cols = board[0].size();

        // boundary checks
        if (r < 0 || r>= rows || c < 0 || c >= cols){
            return;
        }

        char ch = board[r][c];

        if (ch == '#'){
            return;
        }

        TrieNode* nextNode = node->children[ch - 'a'];

        if (nextNode == nullptr){
            return;
        }

        if (nextNode->word != ""){
            result.push_back(nextNode->word);

            nextNode->word= "";
        }

        board[r][c] = '#';

        // explore 4 directions:
        dfs(board, r + 1, c, nextNode, result);
        dfs(board, r - 1, c, nextNode, result);
        dfs(board, r, c + 1, nextNode, result);
        dfs(board, r, c - 1, nextNode, result);

        // backtrack: restore the cell
        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        /**
            Algo: Trie + DFS + Backtrack
        **/

        TrieNode* root = new TrieNode();
        vector<string> result;

        // insert all words into a trie
        for (string& word : words){
            TrieNode* curr = root;

            for (char ch : word){
                int index = ch - 'a';

                if (curr->children[index] == nullptr) {
                    curr->children[index] = new TrieNode();
                }

                curr = curr->children[index];
            }
            curr->word = word;
        }

        // start DFS from every cell on the board
        for (int r = 0; r < board.size(); r++){
            for (int c = 0; c < board[0].size(); c++){
                dfs(board, r, c, root, result);
            }
        }

        return result;

    }
};
