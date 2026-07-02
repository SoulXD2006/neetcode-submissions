class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> jef;
        queue <TreeNode*> hello;
        if(root == nullptr) return jef;
        vector<int> level;
        hello.push(root);
        while (!hello.empty())          // Process one level at a time
            { 
        int levelSize = hello.size();
         level.clear();
        for(int i = 0; i < levelSize; i++){
            auto it = hello.front();
            level.push_back(it -> val);
            hello.pop();
            if(it -> left != nullptr){
                hello.push(it -> left);
            }
            if(it -> right != nullptr){
                hello.push(it -> right);
                
            }
            
        }
         jef.push_back(level);
        }


return jef;
        
    }
};
