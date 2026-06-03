class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int m1 = 0;
        int m2 = numbers.size() - 1;
        int sum = numbers[m1] + numbers[m2] ;
        while( sum!= target ){
            if(target > sum ) m1++;
            else m2--;
           sum = numbers[m1] + numbers[m2] ;
        }  
        numbers.clear();
        numbers.push_back(m1+1);
        numbers.push_back(m2+1);
        return numbers;
    }
};
