class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>m1;
        for(char ch : s){
            m1[ch]++;
        }
        unordered_map<char,int>m2;
        for(char hy : t){
            m2[hy]++;
        }
        if(m1 == m2){
    return true;
}
else
{
    return false;
}
    }
};
