class Solution {
   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a, b;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();
                st.push(b + a);
            } else if (tokens[i] == "-") {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();
                st.push(b - a);
            } else if (tokens[i] == "*") {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();
                st.push(b * a);
            } else if (tokens[i] == "/") {
                int a = st.top();
                st.pop();

                int b = st.top();
                st.pop();
               st.push(b / a);
            }

            else {
                st.push(stoi(tokens[i]));
            }
        }
        int result = st.top();
        return result;
    }
};
