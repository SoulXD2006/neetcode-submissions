class Solution {
public:
    int solve(vector<int>& nums, int n, vector<int>& dp) {
        if (dp[n] != -1) return dp[n];

        int best = 1;   // default: nums[n] alone

        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[n]) {
                best = max(best, 1 + solve(nums, i, dp));   // compare against best, keep updating it
            }
        }

        dp[n] = best;
        return dp[n];
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        int answer = 0;

        for (int i = 0; i < nums.size(); i++) {
            answer = max(answer, solve(nums, i, dp));
        }
        return answer;
    }
};