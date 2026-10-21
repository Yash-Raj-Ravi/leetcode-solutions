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
// void postorder(TreeNode* root,vector<int> &ans)
// {
//     if(root==NULL) return;

//     postorder(root->left,ans);
//     postorder(root->right,ans);
//     ans.push_back(root->val);
// }
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;

//         postorder(root,ans);
        
//         return ans;
//     }
// };

// // 2.Iterative (Using 2 stacks)
// class Solution {
// public:
//     vector<int> postorderTraversal(TreeNode* root) {
//         vector<int> ans;
//         if(root==NULL) return ans;
        
//         stack<TreeNode*> st1, st2;
//         st1.push(root);
//         while(!st1.empty()){
//             st2.push(st1.top());
//             st1.pop();
//             if(st2.top()->left) st1.push(st2.top()->left);
//             if(st2.top()->right) st1.push(st2.top()->right);
//         }

//         while(!st2.empty()){
//             ans.push_back(st2.top()->val);
//             st2.pop();
//         }
//         return ans;
//     }
// };

// 3.Iterative (Using 1 stack)
/*
Rules:
	1.	Go left as much as possible
	2.	Peek the top node
	3.	If it has a right child you haven’t visited, go right
	4.	Else → print it
*/
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(!st.empty() || curr!=NULL){

            if(curr!=NULL){
            st.push(curr);
            curr = curr->left;
            }
            else{
            TreeNode* temp = st.top()->right;
            if(temp==NULL){
                temp = st.top();
                st.pop();
                ans.push_back(temp->val);

                while(!st.empty() && temp==st.top()->right){
                    temp = st.top();
                    st.pop();
                    ans.push_back(temp->val);
                }
            }
            else{
                curr = temp;
            }
        }
        }
        return ans;
    }
};