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
int hi = 0 ;
void good(TreeNode* root, int maxSoFar) {
    if (root == nullptr)
        return ;
    if ( root -> val >= maxSoFar) hi++;
   maxSoFar = max(maxSoFar, root->val);
    good(root->left,maxSoFar);
    good(root->right,maxSoFar);
    

    }
    int goodNodes(TreeNode* root) {
     good(root,root->val);
     return hi;

    }
};
