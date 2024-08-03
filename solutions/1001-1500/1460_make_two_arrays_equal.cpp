/* https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/
1460. Make Two Arrays Equal by Reversing Subarrays
Easy
Map
*/
class Solution
{
public:
    bool canBeEqual(vector<int> &target, vector<int> &arr)
    {
        unordered_map<int, int> freq;
        for (int i : target)
            freq[i]++;
        for (int i : arr)
        {
            if (!freq[i])
                return false;
            freq[i]--;
        }
        return true;
    }
};