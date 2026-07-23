class Solution {
   public:
    bool solve(string &s, vector<string>& wordDict, int n, bool isComplete, vector<int>& dp) {
        if (n == s.size()) return true;

        if (dp[n] != -1) return dp[n];

        string temp;
        dp[n] = 0 ;
        for (int i = n; i < s.size(); i++) {
            temp.push_back(s[i]);
            for (int j = 0; j < wordDict.size(); j++) {
                if (temp == wordDict[j]) {
                    if (solve(s,wordDict ,i+1 ,isComplete ,dp)) {
                        dp[n] = 1;
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        bool isComplete = false;
        isComplete = solve(s, wordDict, 0, isComplete, dp);
        return isComplete;
    }
};
