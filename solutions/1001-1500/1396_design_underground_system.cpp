/* https://leetcode.com/problems/design-underground-system/
1396. Design Underground System
Medium
HashMap
*/
class UndergroundSystem
{
public:
    unordered_map<int, pair<string, int>> starting;
    unordered_map<string, pair<int, int>> averagetime;

    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        starting[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationname, int t)
    {
        string s = starting[id].first + "/" + stationname;
        if (averagetime.count(s) == 0)
            averagetime[s] = make_pair(t - starting[id].second, 1);
        else
        {
            averagetime[s] =
                make_pair(t - starting[id].second + averagetime[s].first, averagetime[s].second + 1);
        }
        starting.erase(id);
    }

    double getAverageTime(string startStation, string endStation)
    {
        string s = startStation + "/" + endStation;
        return double(averagetime[s].first) / double(averagetime[s].second);
    }
};