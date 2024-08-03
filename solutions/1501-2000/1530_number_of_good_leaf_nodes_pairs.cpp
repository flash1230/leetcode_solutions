/* https://leetcode.com/problems/number-of-good-leaf-nodes-pairs/
1530. Number of Good Leaf Nodes Pairs
Medium
Tree DFS
*/
class Solution
{
public:
    int ans;
    int distance;
    vector<int> leaf_dist(TreeNode *root)
    {
        vector<int> distances(distance + 1, 0);
        if (!root->left && !root->right)
        {
            distances[0] = 1;
            return distances;
        }
        else if (!root->left)
        {
            vector<int> temp = leaf_dist(root->right);
            for (int i = 0; i < distance; i++)
                distances[i + 1] = temp[i];
            return distances;
        }
        else if (!root->right)
        {
            vector<int> temp = leaf_dist(root->left);
            for (int i = 0; i < distance; i++)
                distances[i + 1] = temp[i];
            return distances;
        }
        else
        {
            vector<int> t1 = leaf_dist(root->left);
            vector<int> t2 = leaf_dist(root->right);
            for (int i = 0; i < distance; i++)
                distances[i + 1] = t1[i] + t2[i];
            for (int i = 0; i < distance; i++)
            {
                if (!t1[i])
                    continue;
                for (int j = 0; j <= distance - i - 2; j++)
                    ans += t1[i] * t2[j];
            }
        }
        return distances;
    }

    int countPairs(TreeNode *root, int d)
    {
        ans = 0;
        distance = d;
        leaf_dist(root);
        return ans;
    }
};