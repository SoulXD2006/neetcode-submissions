class Solution {
public:
    int solve(vector<int>& nums , int m , int n ,vector<int> &dp){
        
        if(n > nums.size()-1) {
        return 0 ;}
        if(dp[n]!= -1) return dp[n];
       dp[n] = max(nums[n] + solve(nums,m,n+2,dp),solve(nums,m,n+1,dp) );
         return dp[n];
    }

    int solve1(vector<int>& nums , int m , int n ,vector<int> &dp){
        
        if(n > nums.size()-2) {
        return 0 ;}
        if(dp[n]!= -1) return dp[n];
       dp[n] = max(nums[n] + solve1(nums,m,n+2,dp),solve1(nums,m,n+1,dp) );
         return dp[n];
    }


    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int n = nums.size() +1;
        vector<int> values (n+1,-1);
        vector<int> values1 (n+1,-1);
        int max1 = 0;
        int max2 = 0 ; 
        max1 = solve(nums,0,1,values);
        max2 = solve1(nums,0,0,values1);
        int hello =  max (max1,max2);
        return hello;
    }
};
