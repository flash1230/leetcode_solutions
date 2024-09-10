/* https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array
3217. Delete Nodes From Linked List Present in Array
Medium
Linked List
*/
class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_set<int> num(nums.begin(), nums.end());
        while (head != NULL && num.contains(head->val))
            head = head->next;
        if (head == NULL)
            return NULL;
        ListNode *iter = head;
        while (iter->next != NULL)
        {
            if (num.contains(iter->next->val))
                iter->next = iter->next->next;
            else
                iter = iter->next;
        }
        return head;
    }
};