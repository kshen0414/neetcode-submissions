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
    bool isValidBST(TreeNode* root) {
        /*
            Algorithm:
            - let's use inorder traversal (left -> root -> right)
        */

        bool hasPrev = false;
        int preVal = 0;

        return inorderCheck(root, hasPrev, preVal);
    }

    bool inorderCheck(TreeNode* root, bool &hasPrev, int &preVal){
        // base case
        if (root == nullptr){
            return true;
        }

        // recusrively check entire left subtree
        if (!inorderCheck(root->left, hasPrev, preVal)){
            return false;
        }

        // is current value <= previously visited value, BST is invalid
        // BST must be increasing
        if (hasPrev && root->val <= preVal){
            return false;
        }

        preVal = root->val;
        hasPrev = true;

        // recursively check entire right subtree
        return inorderCheck(root->right, hasPrev, preVal);
    }
};

