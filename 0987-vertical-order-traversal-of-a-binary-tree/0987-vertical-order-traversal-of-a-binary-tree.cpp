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

// It can be solved using any traversal out of In,Pre,Post,Level
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //if(root==nullptr) return {};

        map<int, map<int, multiset<int>>> mp; // Map containing sorted vertical and level indices and a multiset containing values at a particular(V,L) in sorted order.
        queue<pair<TreeNode*, pair<int,int>>> q;
        // queue containing {Node,V,L}.
        q.push({root,{0,0}}); 
        vector<vector<int>> ans;
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int x = p.second.first;
            int y = p.second.second;

            mp[x][y].insert(node->val);

            if(node->left) q.push({node->left,{x-1,y+1}});
            if(node->right) q.push({node->right,{x+1,y+1}});
        }
            for(auto p:mp){
                vector<int> vertical;
                for(auto q:p.second){
                    vertical.insert(vertical.end(),q.second.begin(),q.second.end());
                    // vector.insert(position, start_iterator, end_iterator);
                }
            ans.push_back(vertical);
            }
        return ans;
    }
};


// class Solution {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode* root) {
        
//     }
// };