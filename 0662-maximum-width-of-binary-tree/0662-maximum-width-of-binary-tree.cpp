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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        long long maxWidth = -1e9;

        while(!q.empty()){
            TreeNode* node = q.front().second;
            int sz = q.size();
            long long x = q.front().first;
            long long minVal = 1e9;
            long long maxVal = -1e9;
        
            for(int i=0;i<sz;i++){
                long long curr_idx = q.front().first - x;

                TreeNode* node = q.front().second;
                q.pop();
                if(i==0) minVal = curr_idx;
                if(i==sz-1) maxVal = curr_idx;
                
                if(node->left) q.push({2*curr_idx+1,node->left});
                if(node->right) q.push({2*curr_idx+2,node->right});

            }
            maxWidth = max(maxWidth,maxVal-minVal+1);
        }
        return maxWidth;
    }
};

// class Solution {
// public:
//     int widthOfBinaryTree(TreeNode* root) {
        
//     }
// };