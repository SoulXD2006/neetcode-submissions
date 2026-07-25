class Solution {
   public:
    int solve(vector<int>& nums, int i, vector<int>& maxDP, vector<int>& minDP) {
        if (i == 0) {
            maxDP[0] = nums[0];
            minDP[0] = nums[0];
            return maxDP[0];
        }

        if (maxDP[i] != INT_MIN) return maxDP[i];

        solve(nums, i - 1, maxDP, minDP);
        int x = nums[i];
        int a = x;
        int b = x * maxDP[i - 1];
        int c = x * minDP[i - 1];
        maxDP[i] = max({a, b, c});
        minDP[i] = min({a, b, c});

        return maxDP[i];
    }

    int maxProduct(vector<int>& nums) {
        int n = nums.size();

        vector<int> maxDP(n, INT_MIN);
        vector<int> minDP(n, INT_MIN);

        solve(nums, n - 1, maxDP, minDP);

        int ans = INT_MIN;

        for (int x : maxDP) ans = max(ans, x);

        return ans;
    }
};