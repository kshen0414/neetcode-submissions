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

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == nullptr){
            return nullptr;
        }

        // create a temp pointer
        // temp point to what root -> left is pointing to
        TreeNode* temp = root -> left;

        // repoint value root is pointing to
        root -> left = root -> right;
        root -> right = temp;
        
        invertTree(root->left);  // recursively exchange children of right node, until reach nullptr
        invertTree(root->right); // recursively exchange children of left node, until reach nullptr

        return root;
    }
};
