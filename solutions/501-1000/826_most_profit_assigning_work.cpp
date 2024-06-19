/* https://leetcode.com/problems/most-profit-assigning-work
826. Most Profit Assigning Work
Medium
Binary Search Greedy
*/
class Solution
{
public:
    int get_profit(int stn, vector<pair<int, int>> &diff)
    {
        int maxp = 0;
        for (const auto &pair : diff)
        {
            if (pair.first <= stn)
                maxp = pair.second;
            else
                break;
        }
        return maxp;
    }

    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        vector<pair<int, int>> p;
        for (int i = 0; i < profit.size(); i++)
            p.push_back({difficulty[i], profit[i]});
        sort(p.begin(), p.end());
        int max_profit_so_far = 0;
        for (auto &pair : p)
        {
            max_profit_so_far = max(max_profit_so_far, pair.second);
            pair.second = max_profit_so_far;
        }

        int ans = 0;
        for (int i : worker)
            ans += get_profit(i, p);
        return ans;
    }
};