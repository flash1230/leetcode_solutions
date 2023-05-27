/* https://leetcode.com/problems/k-closest-points-to-origin
973. K Closest Points to Origin
Medium
Map Heap
*/
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        int n = points.size();
        if (k >= n)
            return points;
        priority_queue<double> heap;
        unordered_map<double, vector<int>> mp;
        vector<int> distances(n);
        double temp = sqrt((points[0][0] * points[0][0]) + (points[0][1] * points[0][1]));
        vector<int> m{0};
        heap.push(temp);
        mp[temp] = m;
        for (int i = 1; i < n; i++)
        {
            double tem = sqrt((points[i][0] * points[i][0]) + (points[i][1] * points[i][1]));
            if (heap.size() < k)
            {
                heap.push(tem);
                vector<int> nakli_arr;
                if (mp.count(tem))
                {
                    nakli_arr = mp[tem];
                    nakli_arr.push_back(i);
                    mp[tem] = nakli_arr;
                }
                else
                {
                    nakli_arr.push_back(i);
                    mp[tem] = nakli_arr;
                }
            }
            else
            {
                if (heap.top() > tem)
                {
                    heap.pop();
                    heap.push(tem);
                    vector<int> nakli_arr;
                    if (mp.count(tem))
                    {
                        nakli_arr = mp[tem];
                        nakli_arr.push_back(i);
                        mp[tem] = nakli_arr;
                    }
                    else
                    {
                        nakli_arr.push_back(i);
                        mp[tem] = nakli_arr;
                    }
                }
            }
        }
        vector<vector<int>> ans;
        while (!heap.empty())
        {
            for (auto i : mp[heap.top()])
            {
                ans.push_back(points[i]);
            }
            mp.erase(heap.top());
            heap.pop();
        }
        return ans;
    }
};