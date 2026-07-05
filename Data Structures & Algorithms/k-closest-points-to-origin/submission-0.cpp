class Solution {
   public:
    double distanceFromOrigin(int x, int y) { return sqrt(x * x + y * y); }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>,
                       greater<pair<double, vector<int>>>> pq;
        for (int i = 0; i < points.size(); i++) {
            pair<double, vector<int>> p;
            double distance = distanceFromOrigin(points[i][0], points[i][1]);
            p = {distance, points[i]};
            pq.push(p);
        }
        vector<vector<int>> hello;
        pair<double, vector<int>> p;
        for (int i = 0; i < k; i++) {
            p = pq.top();
            hello.push_back(p.second);
            pq.pop();
        }
        return hello;
    }
};
