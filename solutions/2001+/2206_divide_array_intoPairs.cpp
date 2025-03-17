/* https://leetcode.com/problems/divide-array-into-equal-pairs/
2206. Divide Array Into Equal Pairs
Easy
Set
*/
class Solution
{
public:
    bool divideArray(vector<int> &nums)
    {
        set<int> lonely;
        for (int i : nums)
        {
            if (lonely.contains(i))
                lonely.erase(i);
            else
                lonely.insert(i);
        }
        return lonely.empty();
    }
};