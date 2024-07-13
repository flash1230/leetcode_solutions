/* https://leetcode.com/problems/robot-collisions
2751. Robot Collisions
Hard
Stack Sorting
*/
class Solution
{
public:
    vector<int> survivedRobotsHealths(vector<int> &positions, vector<int> &healths, string directions)
    {
        vector<pair<int, pair<int, int>>> robs;
        int l = healths.size();
        for (int i = 0; i < l; i++)
        {
            if (directions[i] == 'R')
                robs.push_back({positions[i], {i, healths[i]}});
            else
                robs.push_back({positions[i], {i, -healths[i]}});
        }
        sort(robs.begin(), robs.end());
        stack<pair<int, int>> st;
        for (int i = 0; i < l; i++)
        {
            if (st.empty() || robs[i].second.second > 0)
                st.push(robs[i].second);
            else
            {
                while (!st.empty())
                {
                    if (st.top().second < 0)
                    {
                        st.push(robs[i].second);
                        break;
                    }
                    else if (-robs[i].second.second > st.top().second)
                    {
                        st.pop();
                        robs[i].second.second++;
                        if (st.empty())
                        {
                            st.push(robs[i].second);
                            break;
                        }
                    }
                    else if (-robs[i].second.second == st.top().second)
                    {
                        st.pop();
                        break;
                    }
                    else
                    {
                        st.top().second--;
                        break;
                    }
                }
            }
        }
        int n = st.size();
        vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--)
        {
            ans[i] = abs(st.top().second);
            st.pop();
        }
        return ans;
    }
};