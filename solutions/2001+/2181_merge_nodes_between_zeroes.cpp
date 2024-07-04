/* https://leetcode.com/problems/merge-nodes-in-between-zeros
2181. Merge Nodes in Between Zeros
Medium
Linked List
*/
class Solution
{
public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *ans = head;
        ListNode *trav = head->next;
        int sum = 0;
        ListNode *ans_trav = new ListNode(0, head);
        while (1)
        {
            if (trav == NULL)
            {
                ans_trav->next = NULL;
                break;
            }
            if (trav->val == 0)
            {
                ans_trav = ans_trav->next;
                ans_trav->val = sum;
                sum = 0;
                trav = trav->next;
            }
            else
            {
                sum += trav->val;
                trav = trav->next;
            }
        }
        return ans;
    }
};