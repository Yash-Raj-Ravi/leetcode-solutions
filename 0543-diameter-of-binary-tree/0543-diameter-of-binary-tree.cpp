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
    int depth(TreeNode* node){
        if(node==NULL) return 0;

        int lh = depth(node->left);
        int rh = depth(node->right);

        return 1 + max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
       if(root==NULL) return 0;
       
       queue<TreeNode*> q;
       q.push(root);
       int maxval = -1e9;

       while(!q.empty()){

        TreeNode* node;

        node = q.front();
        int lh = depth(node->left);
        int rh = depth(node->right);
        maxval = max(maxval,lh+rh);
        q.pop();
        if(node->left) q.push(node->left);
        if(node->right) q.push(node->right);
        
       }
       return maxval;
    }
};