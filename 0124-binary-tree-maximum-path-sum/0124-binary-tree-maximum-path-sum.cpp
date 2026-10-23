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
private:
    int maxsum = INT_MIN;

    int maxPathsum(TreeNode* node) {
        if (node == NULL) return 0;

        int leftSum = max(0,maxPathsum(node->left)); // We are avoiding paths with negative pathsum
        int rightSum = max(0,maxPathsum(node->right));

        maxsum = max(maxsum, node->val + leftSum + rightSum);

        return node->val +  max(leftSum, rightSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxPathsum(root);
        return maxsum;
    }
};



// class Solution {
// public:
//     int maxPathSum(TreeNode* root) {
        
//     }
// };