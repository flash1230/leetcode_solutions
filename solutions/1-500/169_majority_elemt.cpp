/* https://leetcode.com/problems/majority-element/
169. Majority Element
Easy
Map
*/
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (int i : nums)
            freq[i]++;
        int res = 0;
        int val = -1;
        for (auto i : freq)
        {
            if (i.second > val)
            {
                val = i.second;
                res = i.first;
            }
        }
        return res;
    }
};