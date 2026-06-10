class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        stack <int> temp;
        long long lun = 0 ;
        for(int i = 0 ; i < digits.size(); i++){
            temp.push(digits[i]);

        }
        long long  k= 1;
        int j = 0;
        while(!temp.empty()){
            j = temp.top();
            temp.pop();
            lun = lun + j*k;
            k = k*10;
        }
        lun = lun + 1;
        digits.clear();
        int l = 0;
        while(lun!=0){
            l = lun%10;
            temp.push(l);
            lun = lun/10;
        }
        while(!temp.empty()){
            digits.push_back(temp.top());
            temp.pop();
        }
        return digits;
    }
};
