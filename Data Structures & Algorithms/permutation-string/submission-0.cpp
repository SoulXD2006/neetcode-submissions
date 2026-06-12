class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> hi;
        unordered_map<char, int> jack;
        if (s1.size() > s2.size()) return false;
        for (int i = 0; i < s1.size(); i++) {
            hi[s1[i]]++;
        }
        int l = 0;
        int r = 0;
        for (int i = 0; i < s1.size(); i++) {
            jack[s2[i]]++;
        }
        r = s1.size() - 1;
        while (r < s2.size()) {
            if (hi == jack) {
                return true;
            } else {
                jack[s2[l]]--;
                if (jack[s2[l]] == 0) {
                    jack.erase(s2[l]);
                }
                l++;
                
                if (r < s2.size() - 1) {
                    r++;
                    jack[s2[r]]++;
                } else
                    break;
            }
        }
        return false;
    }
};
