/* https://leetcode.com/problems/linked-list-in-binary-tree/
1367. Linked List in Binary Tree
Medium
Linked List Tree
*/
class Solution
{
public:
    bool listFound(ListNode *head, TreeNode *root)
    {
        if (head->next == nullptr)
            return true;
        bool left = false, right = false;
        if (root->left && root->left->val == head->next->val)
            left = listFound(head->next, root->left);
        if (root->right && root->right->val == head->next->val)
            right = listFound(head->next, root->right);
        return left || right;
    }
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        stack<TreeNode *> trav;
        trav.push(root);
        vector<TreeNode *> starts;
        while (!trav.empty())
        {
            if (trav.top() == nullptr)
            {
                trav.pop();
                continue;
            }
            if (trav.top()->val == head->val)
            {
                if (listFound(head, trav.top()))
                    return true;
            }
            TreeNode *temp = trav.top();
            trav.pop();
            trav.push(temp->left);
            trav.push(temp->right);
        }
        return false;
    }
};