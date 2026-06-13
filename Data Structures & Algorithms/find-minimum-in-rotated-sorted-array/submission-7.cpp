class Solution {
   public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        int middle = (low + high) / 2;
        while (low < high) {
            middle = (low + high) / 2;
            if (nums[middle] > nums[high]) {
                low = middle + 1;
            } else {
                high = middle;
            }
        }
        return nums[low];
    }
};
