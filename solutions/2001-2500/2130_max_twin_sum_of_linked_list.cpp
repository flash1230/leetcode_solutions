/* https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
2130. Maximum Twin Sum of a Linked List
Medium
Linked List
*/
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> st;
        int n = 0;
        ListNode *temp = head;
        while(temp!= NULL) {
            n++;
            st.push(temp->val);
            temp = temp->next;
        }
        int ans = 0;
        for(int i = 0;i<n/2; i++) {
            ans = max(ans, st.top() + head->val);
            st.pop();
            head = head->next;
        }
        return ans;
    }
};