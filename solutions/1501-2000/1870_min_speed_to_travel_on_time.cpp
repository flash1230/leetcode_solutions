/* https://leetcode.com/problems/minimum-speed-to-arrive-on-time
1870. Minimum Speed to Arrive on Time
Medium
Binary Search
*/
class Solution
{
public:
    bool isPossible(vector<int> &dist, double hour, int speed)
    {
        double time = 0;
        int n = dist.size();
        for (int i = 0; i < n - 1; i++)
        {
            time += ceil(double(dist[i]) / double(speed));
            if (time > hour)
                return false;
        }
        time += double(dist[n - 1]) / double(speed);
        return (time<=hour);
    }

    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int n = dist.size();
        if (hour <= n - 1)
            return -1;
        int l = 1;
        int x = INT_MIN;
        for (int i = 0; i < n - 1; i++)
            x = max(x, dist[i]);
        int r = ceil(double(dist[n - 1]) / double(hour + 1 - n));
        r = max(x, r);
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (isPossible(dist, hour, mid))
                r = mid;
            else
                l = mid + 1;
        }
        return r;
    }
};