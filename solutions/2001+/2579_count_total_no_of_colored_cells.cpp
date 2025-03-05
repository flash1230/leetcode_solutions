/* https://leetcode.com/problems/count-total-number-of-colored-cells/
2579. Count Total Number of Colored Cells
Medium
*/
class Solution
{
public:
    long long coloredCells(int n)
    {
        long m = n - 1;
        return 2 * m * m + 2 * m + 1;
    }
};