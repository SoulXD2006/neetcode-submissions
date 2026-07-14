class Solution {
public:
       void solve2(vector<vector<int>>& sets, vector<int>& nums, vector<int>& temp, int i ) {
        if (i == nums.size()) {
            
            if(temp.size() == nums.size()){
                sets.push_back(temp);}
            return;
        }
            for(int j = i ; j < nums.size() ; j++){
                
                swap(temp[i],temp[j]);
                solve2(sets,nums,temp,i+1);
               swap(temp[i],temp[j]);
            }
            
        
    }

        


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> sets;
        vector <int> blank;
        blank = nums;
        solve2(sets,nums,blank,0);
        return sets;
    }
};
