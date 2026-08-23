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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
            Algorithm:
                - LCA definition:
                    - the lowest node in the tree that has both nodes as descendants
                    - a node is allowed to be a descendant of itself
                - Input: 2 nodes (p, q)
                - Output: LCA
            Extra Info:
                - for a BST, left is always smaller than right
        */

        // case 1: p, q are smaller than root
        if (p->val < root->val && q->val < root->val){ // LCA is on the left portion
            return lowestCommonAncestor(root->left, p, q);  // search left
        }

        // case 2: p, q are larger than root
        if (p->val > root->val && q->val > root->val){
            return lowestCommonAncestor(root->right, p, q);
        }

        // case 3: p, q are neither larger or smaller than root at the same time
        // or possible root itself equals p or q
        return root;

    }
};
