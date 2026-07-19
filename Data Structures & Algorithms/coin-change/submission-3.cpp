class Solution {
public: 

   int solve (vector<int>& coins, int remaining, vector<int>& dp ){
         if ( remaining == 0 ) return 0 ; 
         if (remaining < 0) return INT_MAX;
        
        if (dp[remaining] != -1) return dp[remaining];  

            int best = INT_MAX;

    for(int i = 0 ; i < coins.size(); i ++){
       int res = solve(coins, remaining - coins[i], dp);
       if (res != INT_MAX) {              
            best = min(best, res + 1);   
        }

    }
      dp[remaining] = best;
      return best ;
   }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        sort(coins.begin(), coins.end(), greater<int>());
        int  n = 0 ;
        int rem = amount ;
       
      n =  solve(coins,rem,dp);
    
    if(n == INT_MAX) return -1;
    else return n ; 
    }
};
