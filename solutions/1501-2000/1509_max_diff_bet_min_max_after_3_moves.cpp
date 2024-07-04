/* https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves
1509. Minimum Difference Between Largest and Smallest Value in Three Moves
Medium
Priority Queue
*/
class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int n = nums.size();
        if (n <= 4)
            return 0;
        priority_queue<int> miq;
        priority_queue<int, vector<int>, greater<int>> maq;
        for (int i : nums)
        {
            if (maq.size() < 4)
            {
                maq.push(i);
                miq.push(i);
            }
            else
            {
                if (miq.top() > i)
                {
                    miq.pop();
                    miq.push(i);
                }
                if (maq.top() < i)
                {
                    maq.pop();
                    maq.push(i);
                }
            }
        }
        int arr[4];
        int i = 3;
        while (!maq.empty())
        {
            arr[i] = maq.top();
            maq.pop();
            i--;
        }
        int ii = 1;
        int ans = arr[0] - miq.top();
        miq.pop();
        while (!miq.empty())
        {
            ans = min(ans, arr[ii] - miq.top());
            miq.pop();
            ii++;
        }
        return ans;
    }
};