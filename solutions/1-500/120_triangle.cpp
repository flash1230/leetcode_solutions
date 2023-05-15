/* https://leetcode.com/problems/triangle/
120. Triangle
Medium
*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        if(n==1) {
            return triangle[0][0];
        }
        triangle[1][0] += triangle[0][0];
        triangle[1][1] += triangle[0][0];
        for(int i = 2; i<n;i++) {
            triangle[i][0] +=triangle[i-1][0];
            for(int j =1;j<i;j++) {
                triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
            triangle[i][i] += triangle[i-1][i-1];
        }
        int min_sum = triangle[n-1][0];
        for(int i =1;i<n;i++) {
            min_sum = min(min_sum, triangle[n-1][i]);
        }
        return min_sum;
    }
};