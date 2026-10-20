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
// class Solution {
// private:
//     void preorder(TreeNode* root,vector<int> &ans){
//         if(root==nullptr) return;

//         ans.push_back(root->val);
//         preorder(root->left,ans);
//         preorder(root->right,ans);
        
//     }
// public:
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         preorder(root,ans);

//         return ans;
//     }
// };

// 2.Iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> st;

        while(root!=NULL || !st.empty()){
            if(root!=NULL){
                ans.push_back(root->val);
                st.push(root);
                root = root->left;
            }       
            else{
                root = st.top();
                st.pop();
                root = root->right;
            }
        }
        return ans;
    }
};