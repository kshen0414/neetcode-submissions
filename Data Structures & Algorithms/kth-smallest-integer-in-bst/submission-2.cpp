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
    int kthSmallest(TreeNode* root, int k) {
        /**
           Algorithm:
           - Note the term of Kth Smallest, the idea is different from Kth Largest
           - We can sort the elements of the BST in a vector using inorder traversal
           - then we check the vector, if it contains the Kth Smallest integer
        **/
        vector<int> result = {};
        storeInorderTraversal(root, result);
        return result[k - 1];
    }

    void storeInorderTraversal(TreeNode* root, vector<int> &result) {
        if (root != nullptr) {
            storeInorderTraversal(root->left, result);
            result.push_back(root->val);
            storeInorderTraversal(root->right, result);
        }
    }
};
