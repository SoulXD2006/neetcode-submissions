class Solution {
public:
    void solve(string digits , string temp , vector<string> &ans , int n){

        if(temp.size()== digits.size()){
            ans.push_back(temp);
            return;
        }
                int num = digits[n] - '0';
                if(digits[n] == '7'  ){
                    temp.push_back( 97 + 3*(num-2));
                solve(digits , temp , ans , n + 1);
                temp.pop_back();

                temp.push_back( 98 + 3*(num-2));
                solve(digits , temp , ans , n + 1);
                 temp.pop_back();

                 temp.push_back(99 + 3*(num-2));
                solve(digits , temp , ans , n + 1);
                 temp.pop_back();
                 temp.push_back(100 + 3*(num-2));
                solve(digits , temp , ans , n + 1);
                 temp.pop_back();


                }
                else if (digits[n] == '8'){
                    temp.push_back( 98 + 3*(num-2));
                    solve(digits , temp , ans , n + 1);
                temp.pop_back();

                temp.push_back( 99 + 3*(num-2));
                solve(digits , temp , ans , n + 1);
                 temp.pop_back();

                 temp.push_back(100 + 3*(num-2));
                solve(digits , temp , ans , n + 1);
                 temp.pop_back();
                }
                 else if (digits[n] == '9'){
                    temp.push_back( 98 + 3*(num-2));
                    solve(digits , temp , ans , n + 1);
                temp.pop_back();

                temp.push_back( 99 + 3*(num-2));
                solve(digits , temp , ans , n + 1);
                 temp.pop_back();

                 temp.push_back(100 + 3*(num-2));
                solve(digits , temp , ans , n + 1);
                 temp.pop_back();
                 temp.push_back(101 + 3*(num-2));
                solve(digits , temp , ans , n + 1);
                 temp.pop_back();
                }
               else { temp.push_back( 97 + 3*(num-2));
                solve(digits , temp , ans , n + 1);
                temp.pop_back();

                temp.push_back( 98 + 3*(num-2));
                solve(digits , temp , ans , n + 1);
                 temp.pop_back();

                 temp.push_back(99 + 3*(num-2));
                solve(digits , temp , ans , n + 1);
                 temp.pop_back();
        }
        

    }

    vector<string> letterCombinations(string digits) {
        //97 - a ascii value
        string temp ;
         vector<string> ans ;
          int n ;
           if (digits.empty())
        return ans;
        solve(digits,temp,ans,0);
        return ans;
    }
};
