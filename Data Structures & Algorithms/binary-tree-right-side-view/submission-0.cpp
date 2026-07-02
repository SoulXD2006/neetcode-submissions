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
    vector<int> rightSideView(TreeNode* root) {
        queue <TreeNode*> hello;
        vector<int> level;
        if(root == nullptr) return level;
        
        hello.push(root);
        while (!hello.empty())          // Process one level at a time
            { 
        int levelSize = hello.size();
        for(int i = 0; i < levelSize; i++){
            auto it = hello.front();
            if(i == levelSize -1) level.push_back(it -> val);
            hello.pop();
            if(it -> left != nullptr){
                hello.push(it -> left);
            }
            if(it -> right != nullptr){
                hello.push(it -> right);
                
            }
            
        }
         
        }
        return level;
    }
};
