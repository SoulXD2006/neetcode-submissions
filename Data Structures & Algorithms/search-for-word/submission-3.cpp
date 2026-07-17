class Solution {
public:

    void solve(vector<vector<char>>& board , string word , int n , int x , int y , int &wow , string &check){
         
         char letter = word[n];
         
         if(board[x][y] == letter){
        check.push_back(board[x][y]);
         board[x][y] = '#';
         }
            else return;
        

        if(check == word) 
        {wow = 1 ;
        board[x][y] = letter;
        return;}
        

            if(x != 0 ) solve(board,word,n+1,x-1,y,wow,check);
            if(y != 0 ) solve(board,word,n+1,x,y-1,wow,check);
            if(x !=board.size()-1 ) solve(board,word,n+1,x+1,y,wow,check);
            if(y != board[x].size()-1 ) solve(board,word,n+1,x,y+1,wow,check);
            board[x][y] = letter;
            check.pop_back();
            return;
        }


        
    
    

    bool exist(vector<vector<char>>& board, string word) {
        string temp; 
        int check = 0 ;
        for(int i = 0 ; i < board.size() ; i++){
            for(int j = 0 ; j < board[i].size() ; j++){
                if(board[i][j]==word[0]){
                    solve(board,word,0,i,j,check,temp);
                }

            }
        }
        if(check == 1) return true;
        else return false;
    }
};
