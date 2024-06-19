/* https://leetcode.com/problems/search-a-2d-matrix
74. Search a 2D Matrix
Medium
Binary Search
*/
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        if (m == 1 && n == 1)
            return target == matrix[0][0];
        if (target < matrix[0][0] || target > matrix[n - 1][m - 1])
            return false;
        int row;
        if (n > 1)
        {
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = (l + r) / 2;
                if (matrix[mid][0] == target || matrix[mid + 1][0] == target)
                    return true;
                if (matrix[mid][0] < target && matrix[mid + 1][0] > target)
                {
                    row = mid;
                    break;
                }
                if (matrix[mid][0] < target)
                {
                    l = mid + 1;
                    if (l == r)
                    {
                        row = r;
                        break;
                    }
                }
                else
                    r = mid - 1;
            }
        }
        else
            row = 0;
        int l = 0;
        int r = m - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (matrix[row][mid] == target)
                return true;
            if (matrix[row][mid] > target)
                r = mid;
            else
                l = mid + 1;
        }
        if (matrix[row][l] == target)
            return true;
        return false;
    }
};