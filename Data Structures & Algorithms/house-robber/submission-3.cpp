class Solution {
public:
    int solve(vector<int>& nums , int m , int n ,vector<int> &dp){
        
        if(n > nums.size()-1) {
        return 0 ;}
        if(dp[n]!= -1) return dp[n];
       dp[n] = max(nums[n] + solve(nums,m,n+2,dp),solve(nums,m,n+1,dp) );
         return dp[n];
    }


    int rob(vector<int>& nums) {
        int n = nums.size() +1;
        vector<int> values (n+1,-1);
        
        int max = 0;
        max = solve(nums,0,0,values);
        return max;
    }
};
