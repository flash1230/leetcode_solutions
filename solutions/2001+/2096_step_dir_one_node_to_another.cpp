/* https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
2096. Step-By-Step Directions From a Binary Tree Node to Another
Medium
Tree DFS
*/
class Solution
{
public:
    string ans = "";
    bool hasIt(TreeNode *root, int target)
    {
        if (root->val == target)
            return true;
        if (root->left == NULL && root->right == NULL)
            return false;
        if (!root->left)
        {
            bool t = hasIt(root->right, target);
            if (t)
                ans += "R";
            return t;
        }
        if (!root->right)
        {
            bool t = hasIt(root->left, target);
            if (t)
                ans += "L";
            return t;
        }
        bool t = hasIt(root->left, target);
        bool u = hasIt(root->right, target);
        if (t)
            ans += "L";
        if (u)
            ans += "R";
        return t || u;
    }

    string getDirections(TreeNode *root, int startValue, int destValue)
    {
        if (startValue == destValue)
            return "";
        hasIt(root, startValue);
        reverse(ans.begin(), ans.end());
        string s1 = ans;
        ans = "";
        hasIt(root, destValue);
        reverse(ans.begin(), ans.end());
        string s2 = ans;
        if (s1.length() == 0)
            return s2;
        string anss = "";
        int i = 0;
        int n = min(s1.length(), s2.length());
        while (i < n)
        {
            if (s1[i] == s2[i])
                i++;
            else
                break;
        }
        for (int j = i; j < s1.length(); j++)
            anss += 'U';
        while (i < s2.length())
            anss += s2[i++];
        return anss;
    }
};