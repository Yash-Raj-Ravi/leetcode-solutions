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

// We could also have used level order traversal to find the height but it would lead to use of Queue Data structure.