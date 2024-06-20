/* https://leetcode.com/problems/magnetic-force-between-two-balls/
1552. Magnetic Force Between Two Balls
Medium
Binary Search
*/

class Solution
{
public:
    bool isPossible(int x, vector<int> &position, int m)
    {
        int prevBallPos = position[0];
        int ballsPlaced = 1;
        for (int i = 1; i < position.size() && ballsPlaced < m; ++i)
        {
            int currPos = position[i];
            if (currPos - prevBallPos >= x)
            {
                ballsPlaced++;
                prevBallPos = currPos;
            }
        }
        return ballsPlaced == m;
    }

    int maxDistance(vector<int> &position, int m)
    {
        sort(position.begin(), position.end());
        int n = position.size();
        if (m == 2)
            return position[n - 1] - position[0];
        int left = 1, right = ceil((position[n - 1] - position[0]) / (m - 1.0)), ans = 1;
        while (right >= left)
        {
            int mid = left + (right - left) / 2;
            if (isPossible(mid, position, m))
            {
                left = mid + 1;
                ans = mid;
            }
            else
                right = mid - 1;
        }
        return ans;
    }
};