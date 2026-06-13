class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        int ans = high;

        while (low <= high) {

            int middle = low + (high - low) / 2;

            long long time = 0;

            for (int i = 0; i < piles.size(); i++) {
                time += (piles[i] + middle - 1) / middle;
            }

            if (time <= h) {
                ans = middle;
                high = middle - 1;
            }
            else {
                low = middle + 1;
            }
        }

        return ans;
    }
};