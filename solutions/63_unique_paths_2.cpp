/* https://leetcode.com/problems/unique-paths-ii/
63. Unique Paths II
Medium
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]) {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(i==0 && j==0) {
                    obstacleGrid[0][0] = 1;
                    continue;
                }
                if(obstacleGrid[i][j]) {
                    obstacleGrid[i][j] = 0;
                    continue;
                }
                if(i==0) {
                    obstacleGrid[i][j] = obstacleGrid[i][j-1];
                }
                else if(j==0) {
                    obstacleGrid[i][j] = obstacleGrid[i-1][j];
                }
                else {
                    obstacleGrid[i][j] = obstacleGrid[i-1][j] + obstacleGrid[i][j-1];
                }
            }
        }
        return obstacleGrid[m-1][n-1];
    }
};