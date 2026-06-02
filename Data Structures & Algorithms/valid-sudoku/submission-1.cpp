class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
    for(char c = '1'; c <= '9'; c++)
{
    m1[c] = 1;
}
        for (int i =0; i < 9 ; i++){
            for (int j =0; j < 9 ; j++){
                if(board[i][j] !='.')
                {
                    m2[board[i][j]]++;}
                    if(m1[board[i][j]] < m2[board[i][j]] && board[i][j] !='.' )
                {return false;}

        }
        m2.clear();}

        for (int i =0; i < 9 ; i++){
            for (int j =0; j < 9 ; j++){
                if(board[j][i] !='.')
                {
                    m2[board[j][i]]++;}
                    if(m1[board[j][i]] < m2[board[j][i]] && board[j][i] !='.' )
                {return false;}

        }
        m2.clear();}

    m2.clear();
    
    for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 3*i; k < 3*i+3; k++) {
                    for (int l = 3*j; l < 3*j+3; l++) {
                            if(board[k][l] !='.')
                              {   m2[board[k][l]]++;}
                               if(m1[board[k][l]] < m2[board[k][l]] && board[k][l] !='.' )
                             {return false;}  }   
                                       if(k == 3*i+2){
                                        m2.clear();
                                       } }   
                                        }   
       m2.clear(); }



    
return true;}};
