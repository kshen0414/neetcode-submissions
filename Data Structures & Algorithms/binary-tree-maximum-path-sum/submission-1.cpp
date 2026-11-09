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
    int maxPathSum(TreeNode* root) {
        /**
            Algo: DFS (PostOrder Traversal)

            Note:
            - A valid path cannot visit the same node twice
            - we can calculate the best path contribution for each subtree
              - starting from the bottom and working upward
        **/

        int res = root->val;

        // compute max path sum and store in res
        findMaxSumRec(root, res);

        return res;
    }

    int findMaxSumRec(TreeNode* root, int &res) {
        if (root == nullptr){  // base case
            return 0;
        }

        int left = max(0, findMaxSumRec(root->left, res));  // best left contribution
        int right = max(0, findMaxSumRec(root->right, res));  // best right contribution

        // check complete path
        res = max(res, left + right + root->val);

        return root->val + max(left, right);  // return single branch
    }
};
