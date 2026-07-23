class Solution {
public:
    int solve(string s , int n , vector <int> &dp ){
     if (n == s.size()) return 1;

     if(dp[n]!=-1) return dp[n];
    if(n== s.size() -1 &&  s[n] > '0'){
        dp[n] = solve(s,n+1,dp);
         return dp[n];
    }
    int num2 = (s[n] - '0') * 10 + (s[n + 1] - '0');
     if(num2 >= 10 && num2 <= 26) {
        dp[n] = solve(s,n+2,dp) + solve(s,n+1,dp);
     }
  else if( s[n] > '0') dp[n] = solve(s,n+1,dp);
  else return 0;
        return dp[n];
    }



    int numDecodings(string s) {
        vector <int> dp (s.size()+1, -1);
        int max = solve(s,0,dp);
        return max;
    }
};
