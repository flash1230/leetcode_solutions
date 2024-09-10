/* https://leetcode.com/problems/split-linked-list-in-parts/
725. Split Linked List in Parts
Medium
Linked List
*/
class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        vector<ListNode *> ans(k);
        if (head == nullptr)
            return ans;
        int n = 0;
        ListNode *lf = head;
        unordered_map<int, ListNode *> pos;
        while (lf != nullptr)
        {
            pos[n] = lf;
            n++;
            lf = lf->next;
        }
        int each = n / k;
        int extra = n % k;
        lf = head;
        n = 0;
        for (int i = 0; i < k; i++)
        {
            ans[i] = pos[n];
            pos[n + each - 1 + (extra > 0)]->next = NULL;
            n += each + (extra > 0);
            extra--;
            if (!pos.contains(n))
                break;
        }
        return ans;
    }
};