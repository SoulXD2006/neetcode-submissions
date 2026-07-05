class KthLargest {
public:
 vector<int> check;
 int j = 0;
    KthLargest(int k, vector<int>& nums) {
        check = nums;
        j = k;
    }
    
    int add(int val) {
        check.push_back(val);
        sort(check.begin(),check.end());
        return check[check.size()-j];
    }
};
