/* https://leetcode.com/problems/add-two-numbers-ii/
445. Add Two Numbers II
Medium
Linked List Stack
*/
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        stack<ListNode *> st1, st2;
        ListNode *p1 = l1;
        while (p1)
        {
            st1.push(p1);
            p1 = p1->next;
        }
        p1 = l2;
        while (p1)
        {
            st2.push(p1);
            p1 = p1->next;
        }
        int carry = 0;
        while (st1.size() && st2.size())
        {
            int t = st1.top()->val + st2.top()->val + carry;
            st1.top()->val = t % 10;
            st2.top()->val = t % 10;
            carry = t / 10;
            st1.pop();
            st2.pop();
        }
        if (st1.empty() && st2.empty())
        {
            if (!carry)
                return l1;
            else
            {
                ListNode *temp = new ListNode(1, l1);
                return temp;
            }
        }
        else
        {
            if (!st1.empty())
            {
                while (!st1.empty())
                {
                    if (!carry)
                        return l1;
                    int t = st1.top()->val + carry;
                    st1.top()->val = t % 10;
                    carry = t / 10;
                    st1.pop();
                }
                if (carry)
                {
                    ListNode *temp = new ListNode(1, l1);
                    return temp;
                }
                return l1;
            }
            else
            {
                while (!st2.empty())
                {
                    if (!carry)
                        return l2;
                    int t = st2.top()->val + carry;
                    st2.top()->val = t % 10;
                    carry = t / 10;
                    st2.pop();
                }
                if (carry)
                {
                    ListNode *temp = new ListNode(1, l2);
                    return temp;
                }
                return l2;
            }
        }
        return l1;
    }
};