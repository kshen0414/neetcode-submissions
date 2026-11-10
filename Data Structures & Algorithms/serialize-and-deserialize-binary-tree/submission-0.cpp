/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:
    void serializePreOrder(TreeNode* root, string& data){
        if (root == nullptr){
            data += "# ";
            return;
        }

        data += to_string(root->val) + " ";
        serializePreOrder(root->left, data);
        serializePreOrder(root->right, data);
    }


    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        // preorder DFS (root --> left --> right)
        
        string data = "";
        serializePreOrder(root, data);
        return data;
    }

    TreeNode* deserializePreOrder(stringstream& ss){
        string value;
        ss >> value;

        if (value == "#"){
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(value));

        root->left = deserializePreOrder(ss);
        root->right = deserializePreOrder(ss);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializePreOrder(ss);
    }
};
