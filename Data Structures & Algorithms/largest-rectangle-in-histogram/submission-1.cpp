class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
       
        int area = 0 ;
        int j = 1 ; 
        int h = heights[0];
        int max = 0;
       
        for(int i = 0 ; i <  heights.size() ;i++){
            h = heights[i];
            j = i;
            while(j < heights.size()){
                if(heights[j] < h ){

                    h = heights[j];
                }
                area = (j - i + 1) * h;
                if (area > max ){
                    max = area ;
                }
                j++;

            }
        }
  return max ;  }
};
