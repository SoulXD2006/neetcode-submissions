class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
    priority_queue<int> maxheap(stones.begin(), stones.end());
    while(maxheap.size()>1){
        int j = maxheap.top();
        maxheap.pop();
        int k = maxheap.top();
        maxheap.pop();
        int lol = j - k;
        if(j-k > 0) maxheap.push(lol);
    }
    if(maxheap.size()==0) return 0;
    return maxheap.top();
    }
};
