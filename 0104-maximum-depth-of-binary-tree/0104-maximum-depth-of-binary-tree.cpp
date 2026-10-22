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

// // 1.Recursive
// // Takes O(N) space in worst case.
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {
//         int x,y;
//         if(root!=NULL){
//             x = maxDepth(root->left);
//             y = maxDepth(root->right);

//             if(x>y) return x+1;
//             else return y+1;
//         }
//         return 0;
//     }
// };

// 2.Recursive (Striver)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;

        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);

        return 1 + max(leftHeight,rightHeight);
    }
};

// // 3.Using Level Order Traversal
// class Solution {
// public:
//     int maxDepth(TreeNode* root) {

//         vector<vector<int>> ans;
//         if(root==NULL) return 0;

//         queue<TreeNode*> q;
//         q.push(root);
    
//         while(!q.empty()){
//             int sz = q.size();
    
//             vector<int> level;

//             for(int i=0;i<sz;i++){
//                 TreeNode* node = q.front();
//                 q.pop();
//                 level.push_back(node->val);
//                 if(node->left) q.push(node->left); 
//                 if(node->right) q.push(node->right);    
//             }
//             ans.push_back(level);
//         }
//     return ans.size();
//     }
// };
