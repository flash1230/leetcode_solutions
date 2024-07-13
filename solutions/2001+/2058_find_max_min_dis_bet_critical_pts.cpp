/* https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points
2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
Medium
Linked List
*/
class Solution
{
public:
    vector<int> nodesBetweenCriticalPoints(ListNode *head)
    {
        vector<int> ans{INT_MAX, -1};
        int first = 0, prev, prev_num2 = head->val, prev_num = head->next->val, iter = 1;
        head = head->next->next;
        while (head)
        {
            if ((prev_num > prev_num2 && head->val < prev_num) || (prev_num < prev_num2 && head->val > prev_num))
            {
                if (!first)
                    first = iter;
                else
                {
                    ans[0] = min(ans[0], iter - prev);
                    ans[1] = max(ans[1], iter - first);
                }
                prev = iter;
            }
            prev_num2 = prev_num;
            prev_num = head->val;
            head = head->next;
            iter++;
        }
        if (ans[1] == -1)
        {
            ans[0] = -1;
            return ans;
        }
        return ans;
    }
};