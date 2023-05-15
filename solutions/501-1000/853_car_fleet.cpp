/* https://leetcode.com/problems/car-fleet/
853. Car Fleet
Medium
Stack
*/
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> vect;
        for(int i = 0;i<position.size();i++) {
            vect.push_back(make_pair(position[i], speed[i]));
        }
        sort(vect.begin(), vect.end());
        stack<double> s;
        s.push(double(target-vect[0].first)/vect[0].second);
        for(int i = 1;i<position.size();i++) {
            double res = double(target-vect[i].first)/vect[i].second;
            while( !s.empty() && res >= s.top()) {
                s.pop();
            }
            s.push(res);
        }
        int ans=0;
        while(!s.empty()) {
            s.pop();
            ans++;
        }
        return ans;
    }
};