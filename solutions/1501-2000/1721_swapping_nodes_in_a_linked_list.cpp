/* https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
1721. Swapping Nodes in a Linked List
Medium
Linked List
*/
class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *p1 = head;
        for (int i = 1; i < k; i++)
            p1 = p1->next;
        ListNode *p2 = p1;
        int count = 0;
        while (p2->next != NULL)
        {
            count++;
            p2 = p2->next;
        }
        if (count < k - 1)
        {
            p2 = head;
            for (int i = 0; i < count; i++)
                p2 = p2->next;
            swap(p1->val, p2->val);
        }
        if (count > k - 1)
        {
            p2 = p1;
            for (int i = 0; i <= count - k; i++)
                p2 = p2->next;
            swap(p1->val, p2->val);
        }
        return head;
    }
};