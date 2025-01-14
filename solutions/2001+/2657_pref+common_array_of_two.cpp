/* https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
2657. Find the Prefix Common Array of Two Arrays
Medium
*/
class Solution
{
public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        vector<int> ans(n);
        vector<int> freq(n, 0);
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] == B[i])
            {
                count++;
                ans[i] = count;
                continue;
            }
            freq[A[i] - 1]++;
            freq[B[i] - 1]++;
            if (freq[A[i] - 1] == 2)
                count++;
            if (freq[B[i] - 1] == 2)
                count++;
            ans[i] = count;
        }
        return ans;
    }
};