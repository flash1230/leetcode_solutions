/* https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
1524. Number of Sub-arrays With Odd Sum
Medium
DP
*/
class Solution
{
public:
    int numOfSubarrays(vector<int> &arr)
    {
        int sum = 0;
        for (int i = 0, odd = 0; i < arr.size(); ++i)
        {
            if (arr[i] % 2)
                odd = (i - odd) + 1;
            sum = (sum + odd) % 1000000007;
        }
        return sum;
    }
};