/* https://leetcode.com/problems/average-waiting-time
1701. Average Waiting Time
Medium
*/
class Solution
{
public:
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        double ans = 0;
        int time = customers[0][0];
        for (auto i : customers)
        {
            ans += i[1];
            if (time > i[0])
                ans += time - i[0];
            time = i[1] + max(time, i[0]);
        }
        return ans / customers.size();
    }
};