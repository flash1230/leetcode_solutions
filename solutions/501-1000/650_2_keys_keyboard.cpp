/* https://leetcode.com/problems/2-keys-keyboard/
650. 2 Keys Keyboard
Medium
DP
*/
class Solution
{
public:
    int minSteps(int n)
    {
        vector<int> mem(1001, -1);
        mem[1] = 0;
        val(n, mem);
        return mem[n];
    }
    void val(int n, vector<int> &mem)
    {
        if (mem[n] > -1)
            return;
        mem[n] = 1000;
        for (int i = sqrt(n); i >= 1; i--)
        {
            if (n % i == 0)
            {
                val(i, mem);
                if (i == 1)
                {
                    mem[n] = min(mem[i] + (n / i - 1) + 1, mem[n]);
                    return;
                }
                val(n / i, mem);
                mem[n] = min(mem[n], mem[n / i] + i - 1) + 1;
            }
        }
    }
};