class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> count;

        for (int i = 0; i < 128; i++) {
            count[(char)i] = -1;
        }
        int l = 0;
        int r = 0;
        int lenght = 0;
        lenght = 0;
        if (s.size() == 0) return 0;
        while (r < s.size()) {
            if (count[s[r]] == -1 || count[s[r]] < l  ) {
                count[s[r]] = r;
                if (r - l + 1  > lenght) {
                    lenght = r - l +1 ;
                }
                r++;
               
            } else if (count[s[r]] != -1) {
                l = 1 + count[s[r]];
                count[s[r]] = r;
                r++;
            }
            
        }
        return lenght;
    }
};
