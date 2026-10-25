/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// class Solution {
// private:
//     bool Path(TreeNode* &root, TreeNode* &p,vector<TreeNode*> &PathtoX){
        
//         if(root==NULL) return false;

//         PathtoX.push_back(root);

//         if(root==p) return true;

//         if (Path(root->left, p, PathtoX) || Path(root->right, p, PathtoX)) { return true; }

//         PathtoX.pop_back();
//         return false;
//     }
// public:
//     TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//         vector<TreeNode*> PathtoP;
//         vector<TreeNode*> PathtoQ;

//         Path(root,p,PathtoP);
//         Path(root,q,PathtoQ);

//         int m = PathtoP.size()-1;
//         int n = PathtoQ.size()-1;

//         TreeNode* ans = NULL;

//         for(int i=0;i<=min(m,n);i++){
//             if(PathtoP[i]==PathtoQ[i]) ans = PathtoP[i];
//             else break;
//         }
//         return ans;
//     }
// };

// Optimal
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==NULL || root==p || root==q) return root;
    // If Both childs Null then return null, else if p found return p and if q found return q.

    TreeNode* left = lowestCommonAncestor(root->left,p,q);
    TreeNode* right = lowestCommonAncestor(root->right,p,q);

    if(left==NULL) return right; // Left NULL, Right not NULL
    else if(right==NULL) return left; // Left Not NULL, Right NULL
    else return root; // Left Not NULL, Right not NULL (Found the LCA)

    }
};