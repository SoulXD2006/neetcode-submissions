class Solution {
public:
    void solve(vector<vector<int>> &sets , vector<int>& nums, vector<int>& temp , int i ){
       if (i == nums.size()) {
           sets.push_back(temp);
            return;
}

        temp.push_back(nums[i]);
        
        solve(sets,nums,temp,i+1);

        temp.pop_back();

        
        solve(sets,nums,temp,i+1);
    }





    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets;
        vector <int> blank;
        solve(sets,nums,blank,0);

        return sets;



    }
};
