/* https://leetcode.com/problems/count-number-of-nice-subarrays/
1248. Count Number of Nice Subarrays
Medium
Queue Two Pointers
*/
class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        queue<int> mq;
        int ans = 0;
        int prev = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] % 2)
                mq.push(i);
            if (mq.size() > k)
            {
                prev = mq.front();
                mq.pop();
            }
            if (mq.size() == k)
                ans += mq.front() - prev;
        }
        return ans;
    }
};