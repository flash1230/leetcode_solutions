/* https://leetcode.com/problems/defuse-the-bomb/
1652. Defuse the Bomb
Easy
Sliding Window
*/
class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        if (k == 0)
        {
            vector<int> res(n, 0);
            return res;
        }
        vector<int> res;
        int left = 1, right = k;
        int sum = 0;
        if (k < 0)
        {
            left = n + k;
            right = n - 1;
        }
        for (int i = left; i <= right; i++)
            sum += code[i];
        for (int i = 0; i < n; i++)
        {
            res.push_back(sum);
            sum -= code[left % n];
            sum += code[(right + 1) % n];
            left++;
            right++;
        }
        return res;
    }
};