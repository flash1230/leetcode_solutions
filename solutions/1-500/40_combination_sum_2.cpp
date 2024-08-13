/* https://leetcode.com/problems/combination-sum-ii/
40. Combination Sum II
Medium
Backtracking
*/
class Solution
{
public:
    vector<vector<int>> ans;
    void backtracker(vector<int> current, int index, int target, vector<int> &candidates)
    {
        if (target == 0)
        {
            ans.push_back(current);
            return;
        }
        for (int i = index; i < candidates.size() && target >= candidates[i]; ++i)
        {
            if (i == index || candidates[i] != candidates[i - 1])
            {
                current.push_back(candidates[i]);
                backtracker(current, i + 1, target - candidates[i], candidates);
                current.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> current;
        backtracker(current, 0, target, candidates);
        return ans;
    }
};