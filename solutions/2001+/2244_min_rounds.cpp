/* https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
2244. Minimum Rounds to Complete All Tasks
Medium
*/
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map <int, int> freq;
        int ans=0;
        for(int i: tasks) {
            freq[i]++;
        }
        for(auto i: freq) {
            int x = i.second;
            if(x<2) {
                return -1;
            }
            else{
                if(x%3 == 0) {
                    ans+= x/3;
                }
                else {
                    ans+=(x/3) + 1;
                }
            }
        }
        return ans;
    }
};