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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        /**
            Algorithm:
                - traverse main tree, at each node check whether the entire subtree rooted at that node
                - is identical to subRoot
                - if matches, return true, if no node matches after traversing the whole tree, return false
        **/

        if (root == nullptr){
            return false;
        }

        if(isSameTree(root, subRoot)){
            return true;
        }

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

    bool isSameTree(TreeNode* root, TreeNode* subRoot){

        // nullptr case
        if (root == nullptr && subRoot == nullptr){
            return true;
        }

        // either tree is nullptr
        if (root == nullptr || subRoot == nullptr){
            return false;
        }

        if (root->val != subRoot->val){
            return false;
        }

        return isSameTree(root->left, subRoot->left) && isSameTree(root->right, subRoot->right);
    }

};
