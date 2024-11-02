/* https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair
1942. The Number of the Smallest Unoccupied Chair
Medium
Priority Queue
*/
class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int target = times[targetFriend][0];
        sort(times.begin(), times.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int max_filled = 0;
        set<int> vacant;
        for (auto i : times)
        {
            while (!pq.empty() && pq.top().first <= i[0])
            {
                vacant.insert(pq.top().second);
                pq.pop();
            }
            int curchair;
            if (!vacant.empty())
            {
                curchair = *vacant.begin();
                vacant.erase(vacant.begin());
            }
            else
            {
                curchair = max_filled;
                max_filled++;
            }
            if (i[0] == target)
                return curchair;
            pq.push({i[1], curchair});
        }
        return 0;
    }
};