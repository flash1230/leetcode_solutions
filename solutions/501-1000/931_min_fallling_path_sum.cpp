/* https://leetcode.com/problems/minimum-falling-path-sum/
931. Minimum Falling Path Sum
Medium
*/
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1) {
            return matrix[0][0];
        }
        int min_sum = INT_MAX;
        for(int i = 1; i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(j == 0) {
                    matrix[i][j] += min(matrix[i-1][j], matrix[i-1][j+1]);
                    if(i==n-1) {
                        min_sum = min(min_sum, matrix[i][j]);
                    }
                }
                else if(j==n-1) {
                    matrix[i][j] += min(matrix[i-1][j], matrix[i-1][j-1]);
                    if(i==n-1) {
                        min_sum = min(min_sum, matrix[i][j]);
                    }
                }
                else {
                    matrix[i][j]+=min(matrix[i-1][j], min(matrix[i-1][j-1], matrix[i-1][j+1]));
                    if(i==n-1) {
                        min_sum = min(min_sum, matrix[i][j]);
                    }
                }
            }
        }
        return min_sum;
    }
};
