class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = 0;
         int r = 1;
        int max = 0;
        int temp = 0;
        while(r <= prices.size() -1 ){
            temp = prices[r] - prices[l];
            if(temp < 0){
                l++;
            }
            else if ( temp > max){
                max = temp;
            }
            else r++;

        }
    return max;
    }
};
