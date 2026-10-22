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

// // 1.My solution (Not Optimal)
// class Solution {
// private:
//     int depth(TreeNode* node){
//         if(node==NULL) return 0;

//         int lh = depth(node->left);
//         int rh = depth(node->right);

//         return 1 + max(lh,rh);
//     }
// public:
//     int diameterOfBinaryTree(TreeNode* root) {
//        if(root==NULL) return 0;
       
//        queue<TreeNode*> q;
//        q.push(root);
//        int maxval = -1e9;

//        while(!q.empty()){

//         TreeNode* node;

//         node = q.front();
//         int lh = depth(node->left);
//         int rh = depth(node->right);
//         maxval = max(maxval,lh+rh);
//         q.pop();
//         if(node->left) q.push(node->left);
//         if(node->right) q.push(node->right);
        
//        }
//        return maxval;
//     }
// };

// 2.Optimal solution 
class Solution {
private:
    int depth(TreeNode* node,int &diameter){
        if(node==NULL) return 0;

        int lh = depth(node->left,diameter);
        int rh = depth(node->right,diameter);
        diameter = max(diameter,lh+rh);
        return 1 + max(lh,rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
       if(root==NULL) return 0;

       int Diameter = 0;
       depth(root,Diameter); 
       return Diameter;
    }
};