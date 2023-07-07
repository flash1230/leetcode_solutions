/* https://leetcode.com/problems/merge-two-sorted-lists/
21. Merge Two Sorted Lists
Easy
Linked List
*/
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        ListNode *start;
        if (list1->val <= list2->val)
        {
            start = list1;
            list1 = list1->next;
        }
        else
        {
            start = list2;
            list2 = list2->next;
        }
        ListNode *prev = start;
        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                prev->next = list1;
                prev = prev->next;
                list1 = list1->next;
            }
            else
            {
                prev->next = list2;
                prev = prev->next;
                list2 = list2->next;
            }
        }
        if (list1 != NULL)
            prev->next = list1;
        if (list2 != NULL)
            prev->next = list2;
        return start;
    }
};