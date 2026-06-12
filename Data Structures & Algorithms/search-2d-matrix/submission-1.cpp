class Solution {
   public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] <= target){
                row = i;
            } }
        int l  = 0;
        int r = matrix[row].size()-1;
        int middle = (l + r)/2;
        while( l <= r){
            middle = (l + r)/2;
            if(matrix[row][middle]== target) return true;
            else if (matrix[row][middle] < target) {l = middle + 1;}
            else {r = middle - 1;} 
        }
        return false;
    }
};
