/* https://leetcode.com/problems/longest-happy-string/
1405. Longest Happy String
Medium
Priority Queue
*/
class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pair<int, char>> pq;
        if (a > 0)
            pq.push({a, 'a'});
        if (b > 0)
            pq.push({b, 'b'});
        if (c > 0)
            pq.push({c, 'c'});
        string ans;
        while (!pq.empty())
        {
            pair<int, char> prev = pq.top();
            pq.pop();
            int count = prev.first;
            char c = prev.second;
            if (ans.length() >= 2 && ans[ans.size() - 1] == c && ans[ans.size() - 2] == c)
            {
                if (pq.empty())
                    break;
                pair<int, char> temp = pq.top();
                pq.pop();
                ans += temp.second;
                if (temp.first - 1 > 0)
                    pq.push({temp.first - 1, temp.second});
            }
            else
            {
                count--;
                ans = ans + c;
            }
            if (count > 0)
                pq.push({count, c});
        }
        return ans;
    }
};