/* https://leetcode.com/problems/find-the-losers-of-the-circular-game/
2682. Find the Losers of the Circular Game
Easy
*/
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> visited(n+1, false);
        for(int i = 1; i<=n;i++) {
            visited[i] = false;
        }
        int count = 1;
        int i = 1;
        while(!visited[i]){
            visited[i] = true;
            i = (i + (k*count)) % n;
            if(i==0){
                i=n;
            }
            count++;
        }
        vector<int> ans;
        for(int i = 1; i<=n;i++){
            if(!visited[i]) ans.push_back(i);
        }
        return ans;
    }
};