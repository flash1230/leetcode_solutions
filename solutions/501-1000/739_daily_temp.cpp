/* https://leetcode.com/problems/daily-temperatures/
739. Daily Temperatures
Medium
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> vect(temperatures.size(), 0);
        stack<int> s;
        for(int i = 0;i<temperatures.size();i++) {
            if(s.empty()) {
                s.push(i);
            }
            else {
                while(!s.empty() && temperatures[i]>temperatures[s.top()]) {
                    vect[s.top()] = i-s.top();
                    s.pop();
                }
                s.push(i);
            }
        }
        return vect;
    }
};