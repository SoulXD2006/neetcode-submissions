class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        int mini = nums[0];
        int maxi = nums[0];

        // find min and max
        for(int i = 0; i < nums.size(); i++) {
            mini = min(mini, nums[i]);
            maxi = max(maxi, nums[i]);
        }

        int range = maxi - mini + 1;

        // frequency array
        vector<int> freq(range, 0);

        // count frequencies
        for(int i = 0; i < nums.size(); i++) {
            freq[nums[i] - mini]++;
        }

        // bucket sort
        vector<int> bucket[nums.size() + 1];

        for(int i = 0; i < range; i++) {

            if(freq[i] > 0) {

                int actualValue = i + mini;

                bucket[freq[i]].push_back(actualValue);
            }
        }

        vector<int> ans;

        for(int i = nums.size(); i >= 1; i--) {

            for(int j = 0; j < bucket[i].size(); j++) {

                ans.push_back(bucket[i][j]);

                if(ans.size() == k) {
                    return ans;
                }
            }
        }

        return ans;
    }
};