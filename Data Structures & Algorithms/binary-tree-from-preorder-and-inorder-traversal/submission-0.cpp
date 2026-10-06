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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        /**
            Algorithm:
            - preorder: root ---> left ---> right
            - inorder: left ---> root ---> right  
            
            Input:
            ---> preorder = [1, 2, 3, 4]   inorder = [2, 1, 3, 4]

            1. Determine the root from preorder [1]
            2. Determine left, right subtree from inorder
            ---->  [2]  [1]  [3, 4]
            3. From left, right subtree determine root again (scan left to right in preorder style)
        **/
        
        int boundary = 0;
        int preorder_track = 0; 

        // recursively find new root from preorder + recursively determine left, right subtree from inorder
        TreeNode* root = buildSubTree(preorder, inorder, boundary, preorder_track, 0, inorder.size() - 1);
        return root;
    }

    TreeNode* buildSubTree(vector<int>& preorder, vector<int>& inorder, int boundary, int &preorder_track, int inorder_start, int inorder_end){
        
        if(inorder_start > inorder_end){  // base case: out of invalid range
            return nullptr;
        }

        TreeNode* root = new TreeNode();
        int left, right;

        // determine root
        root -> val = preorder[preorder_track];
        preorder_track++;

        // inorder logic: create left, right subtree
        for (int i = inorder_start; i<= inorder_end; i++){
            if(inorder[i] == root->val){
                boundary = i;
            }
        }

        // build left subtree
        root -> left = buildSubTree(preorder, inorder, boundary, preorder_track, inorder_start, boundary - 1);

        // build right subtree
        root -> right = buildSubTree(preorder, inorder, boundary, preorder_track, boundary + 1, inorder_end);


        return root;
    }
};
