/* https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
2807. Insert Greatest Common Divisors in Linked List
Medium
Linked List
*/
class Solution
{
public:
    ListNode *insertGreatestCommonDivisors(ListNode *head)
    {
        ListNode *iter = head;
        while (iter->next != nullptr)
        {
            ListNode *temp = new ListNode(__gcd(iter->val, iter->next->val), iter->next);
            iter->next = temp;
            iter = temp->next;
        }
        return head;
    }
};