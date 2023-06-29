/* https://leetcode.com/problems/add-two-numbers
2. Add Two Numbers
Medium
Linked List
*/
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* ptr1=l1;
        while(l1->next&&l2->next){
            int t = carry;
            carry = (l1->val + l2-> val + t)/10;
            l1->val = (l1->val + l2-> val + t)%10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if(l1->next==NULL ^ l2->next==NULL){
            if(!l1->next){
                swap(l1->next, l2->next);
            }
            int t = carry;
            carry = (l1->val + l2-> val + t)/10;
            l1->val = (l1->val + l2-> val + t)%10;
            l1=l1->next;
            while(l1->next){
                t = carry;
                carry = (l1->val + t)/10;
                l1->val = (l1->val + t)%10;
                l1=l1->next;
            }
            if(carry && l1->val == 9){
                l1->val = 0;
                ListNode* last = new ListNode(1);
                l1->next = last;
            }
            else {
                l1->val+=carry;
            }
        }
        else {
            int t = carry;
            carry = (l1->val + l2-> val + t)/10;
            l1->val = (l1->val + l2->val + t)%10;
            if(carry){
                ListNode* last = new ListNode(1);
                l1->next = last;
            }
        }
        return ptr1;
    }
};