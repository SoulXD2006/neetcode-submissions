class Solution {
public:

    string encode(vector<string>& strs) {
        vector<char> v;
        for(int i = 0; i < strs.size() ;i++){
          for(int j = 0; j <  strs[i].size();j++){
          
            v.push_back(strs[i][j]);
        }
             v.push_back('|');
             v.push_back('|');
        }    
        string s;
        for(int i = 0 ; i < v.size(); i++){
            s += v[i];
        }
        return s;}

    vector<string> decode(string s) {
            vector<string> v;
            string curr ;
            for(int i = 0 ; i < s.size(); i++){
           if(s[i]=='|'&& s[i+1]=='|' ){
            v.push_back(curr);
            curr.clear();
            i++;}
           else curr = curr + s[i];
        }
   return v;  } };
    
