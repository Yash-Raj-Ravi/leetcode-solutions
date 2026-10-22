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

// // 1.My solution
// class Solution {
// private:
//     int depth(TreeNode* node){
//         if(node==NULL) return 0;
//         int lh = depth(node->left); 
//         int rh = depth(node->right);

//         return 1 + max(lh,rh); 
//     }
// public:
//     bool isBalanced(TreeNode* root) {
        
//         if (root == NULL) return true;
//         queue<TreeNode*> q;
//         q.push(root);
//         while(!q.empty()){

//             TreeNode* node = q.front();
//             int diff = depth(node->left) - depth(node->right);

//             if(abs(diff)>1) return false;

//             q.pop();
//             if(node->left) q.push(node->left);
//             if(node->right) q.push(node->right);

//         }
//         return true;
//     }
// };

// 2.Optimal solution
class Solution {
private:
    int depth(TreeNode* node){
        if(node==NULL) return 0;

        int lh = depth(node->left); 
        if(lh==-1) return -1;
        int rh = depth(node->right);
        if(rh==-1) return -1;

        if(abs(lh-rh)>1) return -1;

        return 1 + max(lh,rh); 
    }
public:
    bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        return depth(root)!=-1;
    }
};