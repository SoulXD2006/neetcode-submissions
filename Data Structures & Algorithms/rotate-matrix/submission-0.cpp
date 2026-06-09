class Solution {
   public:
    void rotate(vector<vector<int>>& matrix) {
        int k = 0;
        int n = matrix.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                matrix[j].push_back(matrix[i][j]);
            }
        }
        int j = 0;
        for (int i = 0; i < n; i++) {
           for(int j = 0; j < n ; j++){
                matrix[i].erase(matrix[i].begin());
            
        }
        }
        for (int i = 0; i < n; i++) {
           for(int j = 0; j < n/2; j++){
                k = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = k;
            
        }
        }
    }
};
