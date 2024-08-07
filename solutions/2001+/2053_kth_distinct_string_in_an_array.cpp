/* https://leetcode.com/problems/kth-distinct-string-in-an-array/
2053. Kth Distinct String in an Array
Easy
Map
*/
class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        unordered_map<string, int> distinct;
        for (string s : arr)
            distinct[s]++;
        for (string s : arr)
        {
            if (distinct[s] == 1)
                k--;
            if (k == 0)
                return s;
        }
        return "";
    }
};