/* https://leetcode.com/problems/check-if-it-is-a-straight-line
1232. Check If It Is a Straight Line
Easy
Math
*/
class Solution {
public:
    double c;
    double m;
    bool is_parallel = false;

    void find_slope(vector<int>& p1, vector<int>& p2) {
        if(p1[0] == p2[0]){
            is_parallel = true;
            return;
        }
        m = double(p1[1]-p2[1] ) / double(p1[0] - p2[0]) ;
    }

    void find_constant(int& x, int& y){
        c = y - (m*x);
    }

    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if(n==2)    return true;
        find_slope(coordinates[0], coordinates[1]);
        if(is_parallel) {
            for(int i = 2; i<n;i++) {
                if(coordinates[i][0] != coordinates[0][0])  return false;
            }
            return true;
        }
        find_constant(coordinates[0][0], coordinates[0][1]);
        for(int i = 2; i<n;i++) {
            if(coordinates[i][1] != m*coordinates[i][0] + c){
                return false;
            }
        }
        return true;
    }
};