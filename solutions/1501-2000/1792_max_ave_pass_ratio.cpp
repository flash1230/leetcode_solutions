/* https://leetcode.com/problems/maximum-average-pass-ratio/
1792. Maximum Average Pass Ratio
Medium
Priority Queue Greedy
*/
class Solution
{
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extraStudents)
    {
        priority_queue<pair<double, int>> pq;
        for (int i = 0; i < classes.size(); i++)
        {
            double a = double(classes[i][0] + 1) / double(classes[i][1] + 1);
            double b = double(classes[i][0]) / double(classes[i][1]);
            pq.push({a - b, i});
        }
        while (extraStudents--)
        {
            int aa = pq.top().second;
            pq.pop();
            classes[aa][0]++;
            classes[aa][1]++;
            double a = double(classes[aa][0] + 1) / double(classes[aa][1] + 1);
            double b = double(classes[aa][0]) / double(classes[aa][1]);
            pq.push({a - b, aa});
        }
        double ans = 0.0;
        for (auto clas : classes)
            ans += double(clas[0]) / double(clas[1]);
        return ans / classes.size();
    }
};