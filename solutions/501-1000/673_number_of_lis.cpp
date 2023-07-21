/* https://leetcode.com/problems/number-of-longest-increasing-subsequence/
673. Number of Longest Increasing Subsequence
Medium
*/
class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        vector<set<pair<int, int>>> levels;
        levels.push_back(set<pair<int, int>>());
        levels[0].insert(make_pair(nums[0], 1));
        for (int i = 1; i < nums.size(); i++)
        {
            int j;
            for (j = levels.size() - 1; j >= 0; j--)
            {
                if (nums[i] < levels[j].begin()->first)
                    continue;
                if (nums[i] == levels[j].begin()->first)
                {
                    int g = levels[j].begin()->second;
                    if (j == 0)
                        g += 1;
                    else
                    {
                        for (auto &itr : levels[j - 1])
                        {
                            if (itr.first < nums[i])
                                g += itr.second;
                            else
                                break;
                        }
                    }
                    auto itr = levels[j].begin();
                    levels[j].erase(itr);
                    levels[j].insert(make_pair(nums[i], g));
                    break;
                }
                else
                {
                    int a = 0;
                    for (auto &itr : levels[j])
                    {
                        if (itr.first < nums[i])
                            a += itr.second;
                        else
                            break;
                    }
                    if (j == levels.size() - 1)
                    {
                        levels.push_back(set<pair<int, int>>());
                        levels[levels.size() - 1].insert(make_pair(nums[i], a));
                    }
                    else
                    {
                        levels[j + 1].insert(make_pair(nums[i], a));
                    }
                    break;
                }
            }
            if (j == -1)
            {
                levels[0].insert(make_pair(nums[i], 1));
            }
        }
        int ans = 0;
        for (auto itr : levels[levels.size() - 1])
            ans += itr.second;
        return ans;
    }
};