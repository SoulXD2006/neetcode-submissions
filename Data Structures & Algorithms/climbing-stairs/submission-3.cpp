class Solution {
public:
unordered_map<int,int> memo;
int solve(int n) {
    if (n <= 1) return 1;
    if (memo.count(n)) return memo[n];   // seen this before, don't recompute
    return memo[n] = solve(n-1) + solve(n-2);
}
    int climbStairs(int n) {
        int x;
        x = solve(n);
        return x;

    }
};
