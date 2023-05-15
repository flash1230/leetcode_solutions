/* https://leetcode.com/problems/maximal-square/
221. Maximal Square
Medium
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int cur_max = 0;
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m][n];
        for(int i = 0;i<m;i++) {
            if(matrix[i][0] == '1'){
                cur_max = 1;
                dp[i][0] = 1;
            }
            else {
                dp[i][0] = 0;
            }
        }
           for(int i = 0;i<n;i++) {
                if(matrix[0][i] == '1'){
                    cur_max = 1;
                    dp[0][i] = 1;
                }
               else {
                   dp[0][i] = 0;
               }
            } 
        for(int i = 1;i<m;i++) {
            for(int j = 1;j<n;j++) {
                if(matrix[i][j] == '1') {
                    dp[i][j] = min(min(dp[i-1][j-1], dp[i][j-1]), dp[i-1][j])+1;
                    cur_max = max(cur_max, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return cur_max*cur_max;
    }
};