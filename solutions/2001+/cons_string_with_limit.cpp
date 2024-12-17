/* https://leetcode.com/problems/construct-string-with-repeat-limit/
2182. Construct String With Repeat Limit
Medium
Map Priority Queue Greedy
*/
class Solution
{
public:
    string repeatLimitedString(string s, int repeatLimit)
    {
        unordered_map<char, int> fq;
        for (char c : s)
            fq[c]++;
        string ans;
        priority_queue<char> pq;
        for (auto i : fq)
            pq.push(i.first);
        while (!pq.empty())
        {
            char c = pq.top();
            pq.pop();
            int l = min(repeatLimit, fq[c]);
            for (int i = 0; i < l; i++)
                ans += c;
            fq[c] -= l;
            if (fq[c] > 0 && !pq.empty())
            {
                char nex = pq.top();
                pq.pop();
                ans += nex;
                fq[nex]--;
                if (fq[nex] > 0)
                    pq.push(nex);
                pq.push(c);
            }
        }
        return ans;
    }
};