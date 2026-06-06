class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> track;

        for (int i = 0; i < position.size(); i++) {
            double time = (double)(target - position[i]) / speed[i];
            track.push_back({position[i], time});
        }

        sort(track.begin(), track.end());
        int fleet = position.size();
        double fleettime = track[position.size()-1].second;
        for(int i = position.size() - 2 ; i >= 0 ; i-- ){
            
            if(track[i].second <= fleettime ){
                fleet--;
            }
            else {fleettime = track[i].second;}
        }
    return fleet;}
};
