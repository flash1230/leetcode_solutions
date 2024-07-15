/* https://leetcode.com/problems/create-binary-tree-from-descriptions
2196. Create Binary Tree From Descriptions
Medium
Tree Map
*/
class Solution
{
public:
    TreeNode *createBinaryTree(vector<vector<int>> &descriptions)
    {
        unordered_map<int, TreeNode *> mp;
        unordered_set<int> root;
        for (auto i : descriptions)
        {
            root.insert(i[0]);
            if (!mp.contains(i[0]))
                mp[i[0]] = new TreeNode(i[0]);
            if (mp.contains(i[1]))
            {
                if (i[2])
                    mp[i[0]]->left = mp[i[1]];
                else
                    mp[i[0]]->right = mp[i[1]];
            }
            else
            {
                mp[i[1]] = new TreeNode(i[1]);
                if (i[2])
                    mp[i[0]]->left = mp[i[1]];
                else
                    mp[i[0]]->right = mp[i[1]];
            }
        }
        for (auto i : descriptions)
            root.erase(i[1]);
        return mp[*root.begin()];
    }
};