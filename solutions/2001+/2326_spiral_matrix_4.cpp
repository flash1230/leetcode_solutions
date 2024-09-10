/* https://leetcode.com/problems/spiral-matrix-iv/
2326. Spiral Matrix IV
Medium
Linked List
*/
class Solution
{
public:
    int rows, cols;
    bool in_range(int a, int b)
    {
        if (a < 0 || a >= rows || b < 0 || b >= cols)
            return false;
        return true;
    }
    vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
    {
        rows = m;
        cols = n;
        vector<vector<int>> ans(m, vector<int>(n, -1));
        int i = 0, j = 0;
        int dir = 0;
        while (head != nullptr)
        {
            ans[i][j] = head->val;
            head = head->next;
            if (dir == 0)
                j++;
            else if (dir == 1)
                i++;
            else if (dir == 2)
                j--;
            else
                i--;
            if (!in_range(i, j) || ans[i][j] != -1)
            {
                if (dir == 0)
                {
                    i++;
                    j--;
                }
                else if (dir == 1)
                {
                    j--;
                    i--;
                }
                else if (dir == 2)
                {
                    i--;
                    j++;
                }
                else
                {
                    j++;
                    i++;
                }
                dir++;
                dir %= 4;
            }
        }
        return ans;
    }
};