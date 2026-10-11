/**
Question & Algorithm assumptions:

1. In a typical trie implementation, we have to insert words into a trie, then only search


**/


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

class PrefixTree {
   private:
    TreeNode *root;

   public:
    PrefixTree() {  // the constructor
        root = new TreeNode();
    }

    void insert(string word) {
        TreeNode *temp = root; // both root and temp point to initial node
        for (auto &c : word){
            if (temp -> child[c - 'a'] == nullptr){  
                temp -> child[c - 'a'] = new TreeNode();  // initially child[i] was pointing to nullptr
            }

            temp = temp -> child[c-'a'];  // moves temp pointer to next node
        }
        temp -> end = true;  // if reach the end, then change to true
    }

    bool search(string word) {
        TreeNode *temp = root;
        for (auto &c: word){
            if (temp -> child[c - 'a'] == nullptr){  // we try to match the word by index, for the case of completely new letters
                return false;
            }

            temp = temp -> child[c - 'a'];
        }
        
        return temp -> end; // for example 'do', we stop at 'o' but it is false, unless we insert later
    }

    bool startsWith(string prefix) { // if the prefix matches
        TreeNode *temp = root;
        for (auto &c: prefix){
            if (temp -> child[c - 'a'] == nullptr){
                return false;
            }

            temp = temp -> child[c - 'a'];
        }
        
        return true;

    }
};
