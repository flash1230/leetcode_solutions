/* https://leetcode.com/problems/grumpy-bookstore-owner
1052. Grumpy Bookstore Owner
Medium
Sliding Window
*/
class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        int ans = 0, cur_grump = 0, right = minutes - 1;
        for (int i = 0; i <= right; i++)
        {
            ans += !grumpy[i] * customers[i];
            cur_grump += grumpy[i] * customers[i];
        }
        int max_grump = cur_grump;
        for (int i = right + 1; i < customers.size(); i++)
        {
            ans += !grumpy[i] * customers[i];
            cur_grump = cur_grump - (grumpy[i - minutes] * customers[i - minutes]) + (grumpy[i] * customers[i]);
            max_grump = max(cur_grump, max_grump);
        }
        return ans + max_grump;
    }
};