// define a TreeNode class
class TreeNode {
   public:
    bool end;
    vector<TreeNode*> child;

    TreeNode() {
        this->end = false;

        // vector contains 26 pointers + initialize each new pointer with nullptr
        child.resize(26, nullptr);
    }
};

class WordDictionary {
   private:
    TreeNode* root;

   public:
    WordDictionary() { root = new TreeNode(); }

    //

    void addWord(string word) {
        TreeNode* temp = root;  // both root and temp point to initial node
        for (auto& c : word) {
            if (temp->child[c - 'a'] == nullptr) {
                temp->child[c - 'a'] =
                    new TreeNode();  // initially child[i] was pointing to nullptr
            }

            temp = temp->child[c - 'a'];  // moves temp pointer to next node
        }

        temp->end = true;  // if reach the end, then change to true
    }

    bool search(string word) {
        // need a way to figure out how to handle .xxx wildcard
        return dfs(root, word, 0);
    }

    // recursive helper funciton
    bool dfs(TreeNode* node, string& word, int index) {
        // base case
        if (index == word.size()) {
            return node->end;
        }

        // recursive case #1: 1 character
        if (word[index] != '.') {
            int childIndex = word[index] - 'a';

            if (node->child[childIndex] == nullptr) {
                return false;
            }

            return dfs(node->child[childIndex], word, index + 1);
        }

        // recursive case #2: wildcard .
        else {
            for (int i = 0; i < 26; i++) {
                if (node->child[i] != nullptr) {
                    if (dfs(node->child[i], word, index + 1)) {
                        return true;
                    }
                }
            }
            
            return false;
        }
    }
};
