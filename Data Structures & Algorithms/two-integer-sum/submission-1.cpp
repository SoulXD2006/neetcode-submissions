class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a1=0;
        int a2=0;
        for(int i =0; i < nums.size(); i++){
            int k = nums[i];
             for (int j = i+1; j < nums.size(); j++)
    {
      if(target == nums[i]+ nums[j]){
            a1 = i;
            a2 = j;
            nums.clear();
            nums.push_back(a1);
            nums.push_back(a2);
      }
    }
        }
return nums;
    }
};


