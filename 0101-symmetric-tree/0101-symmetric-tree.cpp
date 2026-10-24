/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        deque<TreeNode*> dq;
        dq.push_back(root);

        while (!dq.empty()) {

            int sz = dq.size();
            int i = 0, j = sz - 1;
            while (i < j) {
                if (dq[i] == NULL && dq[j] == NULL) {
                    i++;
                    j--;
                } else if (dq[i] == NULL || dq[j] == NULL) {
                    return false;
                } else if (dq[i]->val == dq[j]->val) {
                    i++;
                    j--;
                } else {
                    return false;
                }
            }
            for (int j = 0; j < sz; j++) {
                TreeNode* node = dq.front();
                dq.pop_front();

                if (node == NULL) continue;

                dq.push_back(node->left);
                dq.push_back(node->right);
            }
        }
        return true;
    }
};