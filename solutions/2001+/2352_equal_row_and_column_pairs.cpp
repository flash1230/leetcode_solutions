/* https://leetcode.com/problems/equal-row-and-column-pairs
2352. Equal Row and Column Pairs
Medium
Hash Map
*/
class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string, int> freq;
        int n =grid.size();
        for(int i = 0; i<n;i++) {
            string s = "";
            for(int j=0;j<n;j++){
                s+=" ";
                s+=to_string(grid[i][j]);
            }
            freq[s]++;
        }
        int ans = 0;
        for(int i = 0; i<n;i++) {
            string s = "";
            for(int j=0;j<n;j++){
                s+=" ";
                s+=to_string(grid[j][i]);
            }
            if(freq.count(s)){
                ans+=freq[s];
            }
        }
        return ans;
    }
};