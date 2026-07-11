class Solution {
public:

    void solve(vector<int>& nums, int target , vector<vector<int>> &ans ,vector<int> &temp , int sum, int limit){
        if(sum == target){
            ans.push_back(temp);
            return;
        }

        for(int i = limit ; i < nums.size() ; i++){
            if(sum + nums[i] <= target){
                temp.push_back(nums[i]);
                sum = sum + nums[i];
                solve(nums,target,ans,temp,sum,i);
                temp.pop_back();
                sum = sum - nums[i];
            }

        }

    }



    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int sum = 0;
        vector <int> temp;
        solve(nums,target,ans,temp,sum,0);
        return ans;
    }
};
