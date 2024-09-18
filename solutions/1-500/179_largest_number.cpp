/* https://leetcode.com/problems/largest-number/description/
179. Largest Number
Medium
Sorting
*/
class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        vector<string> aphs;
        for (int i : nums)
            aphs.push_back(to_string(i));
        sort(aphs.begin(), aphs.end(), [](string &a, string &b)
             { return a + b > b + a; });
        if (aphs[0] == "0")
            return "0";
        string ans;
        for (string s : aphs)
            ans += s;
        return ans;
    }
};