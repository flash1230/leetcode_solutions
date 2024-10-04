/* https://leetcode.com/problems/divide-players-into-teams-of-equal-skill
2491. Divide Players Into Teams of Equal Skill
Medium
Sorting Map
*/
class Solution1
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        sort(skill.begin(), skill.end());
        int n = skill.size();
        int check = skill[0] + skill[n - 1];
        long long ans = skill[0] * skill[n - 1];
        for (int i = 1; i < (n / 2); i++)
        {
            if (check == skill[i] + skill[n - i - 1])
                ans += skill[i] * skill[n - i - 1];
            else
                return -1;
        }
        return ans;
    }
};

class Solution2
{
public:
    long long dividePlayers(vector<int> &skill)
    {
        int n = skill.size();
        unordered_map<int, int> freq;
        int l = INT_MAX, r = -1;
        for (int i : skill)
        {
            freq[i]++;
            l = min(l, i);
            r = max(r, i);
        }
        int check = l + r;
        int i = 0;
        long long ans = 0;
        cout << check;
        while (!freq.empty())
        {
            if (!freq.contains(skill[i]))
            {
                i++;
                continue;
            }
            if (freq[skill[i]] != freq[check - skill[i]])
                return -1;
            if (skill[i] == check - skill[i])
                ans += (freq[skill[i]] / 2) * pow(skill[i], 2);
            else
                ans += freq[skill[i]] * skill[i] * (check - skill[i]);
            freq.erase(skill[i]);
            freq.erase(check - skill[i]);
            i++;
        }
        return ans;
    }
};