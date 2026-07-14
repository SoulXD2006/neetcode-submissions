class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;

                if (c == ')' && st.top() != '(') return false;

                if (c == '}' && st.top() != '{') return false;

                if (c == ']' && st.top() != '[') return false;

                st.pop();
            }
        }

        return st.empty();
    }

    void solve(int n, vector<string> &ans, int counter, string temp) {
        if (counter == 2*n) {
            if (isValid(temp)) ans.push_back(temp);
            return;
        }
            temp.push_back('(');
            solve(n, ans, counter + 1, temp);
            temp.pop_back();
            temp.push_back(')');
            solve(n, ans, counter + 1,temp);
            
        
    }

    vector<string> generateParenthesis(int n) { 
        string temp; 
    vector<string> ans;
    int counter = 0 ; 
    solve(n,ans,counter,temp);
    return ans;
    
    }
};
