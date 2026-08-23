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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        /*
        Algoritm:
        - Compare the current node from tree p and tree q
        - If both current nodes are nullptr, this branch is the same
        - If only one current node is nullptr, the trees are different
        - If both nodes exist, compare their values
        - If their values are different, the trees are different
        - If their values are the same, continue comparing:
            - left child of p with left child of q
            - right child of p with right child of q
        */

        if (p == nullptr && q == nullptr){ 
            return true;
        }

        if (p == nullptr || q == nullptr){ 
            return false;
        }

        if (p->val != q->val){
            return false;
        }

        
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
