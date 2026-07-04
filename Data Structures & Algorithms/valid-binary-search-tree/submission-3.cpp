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

    bool isValidBST(TreeNode* root) {
        vector <int> way;
        inorder(root,way);
         for(int i = 1 ; i < way.size(); i++){
        if(way[i] <= way[i -1] ) return false;
    }
    return true;
    }
};
