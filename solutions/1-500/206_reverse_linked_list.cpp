/* https://leetcode.com/problems/reverse-linked-list
206. Reverse Linked List
Easy
Linked List
*/
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *cur = head;
        ListNode *nex;
        while (cur != NULL)
        {
            nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        head = prev;
        return head;
    }
};