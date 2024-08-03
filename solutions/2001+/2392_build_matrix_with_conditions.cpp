/* https://leetcode.com/problems/build-a-matrix-with-conditions
2392. Build a Matrix With Conditions
Hard
Graph
*/
class Solution
{
public:
    vector<int> mother_fucking_function(int k, vector<vector<int>> conditions)
    {
        vector<unordered_set<int>> left_up(k);
        vector<unordered_set<int>> right_down(k);
        vector<int> pos;
        for (auto i : conditions)
        {
            left_up[i[1] - 1].insert(i[0] - 1);
            unordered_set<int> temp = right_down[i[1] - 1];
            for (auto ii = temp.begin(); ii != temp.end(); ii++)
            {
                if (left_up[i[0] - 1].contains(*ii))
                    return pos;
                else
                    right_down[i[0] - 1].insert(*ii);
            }
            right_down[i[0] - 1].insert(i[1] - 1);
        }
        unordered_set<int> filled;
        while (filled.size() != k)
        {
            int prev = filled.size();
            int i = 0;
            while (i < k)
            {
                for (auto iter = filled.begin(); iter != filled.end(); iter++)
                    left_up[i].erase(*iter);
                if (!filled.contains(i) && left_up[i].empty())
                {
                    pos.push_back(i + 1);
                    filled.insert(i);
                }
                i++;
            }
            if (prev == filled.size())
            {
                vector<int> temp;
                return temp;
            }
        }
        return pos;
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions,
                                    vector<vector<int>> &colConditions)
    {
        vector<vector<int>> anss;
        vector<vector<int>> filler(k + 1, vector<int>(2));
        vector<int> pos = mother_fucking_function(k, rowConditions);
        if (pos.empty())
            return anss;
        else
        {
            for (int i = 0; i < k; i++)
                filler[pos[i]][0] = i;
        }
        pos = mother_fucking_function(k, colConditions);
        if (pos.empty())
            return anss;
        else
        {
            for (int i = 0; i < k; i++)
                filler[pos[i]][1] = i;
        }
        vector<vector<int>> ans(k, vector<int>(k, 0));
        for (int i = 1; i < filler.size(); i++)
            ans[filler[i][0]][filler[i][1]] = i;
        return ans;
    }
};