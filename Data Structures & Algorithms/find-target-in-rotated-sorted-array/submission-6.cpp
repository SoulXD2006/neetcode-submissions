class Solution {
   public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        int middle = 0;
        int cut = 0;
        // find the cut
        while (low <= high) {
            middle = (low + high) / 2;
            if (middle == nums.size() - 1 || nums[middle] > nums[middle + 1]) {
                cut = middle;
                break;
            } else if (nums[middle] < nums[high] && nums[low] > nums[high]) {
                high = middle - 1;
            } else
                low = middle + 1;
        }
        
    

    // lower part
    low = 0;
    high = cut;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }}
        // u[[er]]
        low = cut + 1;
        high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

    return -1;
}};
