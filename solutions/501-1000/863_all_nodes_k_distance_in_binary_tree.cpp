/* https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
863. All Nodes Distance K in Binary Tree
Medium
Tree BFS
*/
class Solution
{
public:
    vector<TreeNode *> parents;
    vector<int> solve(TreeNode *root, int k)
    {
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        int row = 0;
        int current_row = 1;
        int next_row = 0;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            if (temp->left)
            {
                q.push(temp->left);
                next_row++;
            }
            if (temp->right)
            {
                q.push(temp->right);
                next_row++;
            }
            q.pop();
            current_row--;
            if (current_row == 0)
            {
                current_row = next_row;
                next_row = 0;
                row++;
                if (row == k)
                    break;
            }
        }
        while (current_row--)
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }

    vector<int> solve2(TreeNode *root, int k)
    {
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(parents[root->val]);
        int row = 1;
        int current_row = 1;
        int next_row = 0;
        vector<bool> visited(501, false);
        visited[root->val] = true;
        while (!q.empty())
        {
            if (row == k)
                break;
            TreeNode *temp = q.front();
            visited[temp->val] = true;
            if (temp->left && !visited[temp->left->val])
            {
                q.push(temp->left);
                next_row++;
            }
            if (temp->right && !visited[temp->right->val])
            {
                q.push(temp->right);
                next_row++;
            }
            if (parents[temp->val] && !visited[parents[temp->val]->val])
            {
                q.push(parents[temp->val]);
                next_row++;
            }
            q.pop();
            current_row--;
            if (current_row == 0)
            {
                current_row = next_row;
                next_row = 0;
                row++;
            }
        }
        while (current_row--)
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }

    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        vector<int> ans;
        queue<TreeNode *> q;
        q.push(root);
        parents.resize(501, NULL);
        if (root == target)
        {
            if (k == 0)
            {
                ans.push_back(root->val);
                return ans;
            }
            else
                return solve(root, k);
        }
        int current_row = 1;
        int next_row = 0;
        while (!q.empty())
        {
            TreeNode *temp = q.front();
            if (temp->left)
            {
                parents[temp->left->val] = temp;
                if (temp->left == target)
                {
                    if (k == 0)
                    {
                        ans.push_back(temp->left->val);
                        return ans;
                    }
                    ans = solve(temp->left, k);
                    vector<int> a1 = solve2(temp->left, k);
                    ans.insert(ans.end(), a1.begin(), a1.end());
                    return ans;
                }
                q.push(temp->left);
                next_row++;
            }
            if (temp->right)
            {
                parents[temp->right->val] = temp;
                q.push(temp->right);
                if (temp->right == target)
                {
                    if (k == 0)
                    {
                        ans.push_back(temp->right->val);
                        return ans;
                    }
                    ans = solve(temp->right, k);
                    vector<int> a1 = solve2(temp->right, k);
                    ans.insert(ans.end(), a1.begin(), a1.end());
                    return ans;
                }
                next_row++;
            }
            q.pop();
            current_row--;
            if (current_row == 0)
            {
                current_row = next_row;
                next_row = 0;
            }
        }
        return ans;
    }
};