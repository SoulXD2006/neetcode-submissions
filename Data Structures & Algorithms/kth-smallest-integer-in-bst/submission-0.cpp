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
void inorder(TreeNode* root , vector<int>& way) {
    if(root == nullptr) return;
    inorder(root -> left , way);
    way.push_back(root->val);
    inorder(root -> right , way);
 }
    int kthSmallest(TreeNode* root, int k) {
        vector <int> way;
        inorder(root,way);
        int j = way[k-1];
        return j;
    }
};
