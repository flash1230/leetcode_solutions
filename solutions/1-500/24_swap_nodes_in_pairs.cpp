/* https://leetcode.com/problems/swap-nodes-in-pairs/
24. Swap Nodes in Pairs
Medium
Linked List
*/
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *temp = swapPairs(head->next->next);
        ListNode *t = head;
        head = head->next;
        head->next = t;
        head->next->next = temp;
        return head;
    }
};