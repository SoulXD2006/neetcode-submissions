class Solution {
   public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int maxFreq = 0;
        char most;
        int len = 0;
        int l = 0;
        int r = 0;
        int ans = 0;

        for (int r = 0; r < s.size(); r++) {
            freq[s[r]]++;
            for (auto& p : freq) {
                if (p.second > maxFreq) {
                    maxFreq = p.second;
                    most = p.first;
                }
            }
            len = r - l + 1;
            if (len - maxFreq <= k)
                ans = max(ans, len);
            else {
                freq[s[l]]--;
                freq[s[r]]--;
                r--;
                l++;
            }
        }

        return ans;
    }
};
