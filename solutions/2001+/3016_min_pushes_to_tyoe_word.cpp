/* https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
3016. Minimum Number of Pushes to Type Word II
Medium
Map Sorting
*/
class Solution
{
public:
    int minimumPushes(string word)
    {
        int n = word.length();
        if (n < 9)
            return n;
        vector<int> freq(26, 0);
        for (char c : word)
            freq[int(c) - 97]++;
        if (freq.size() < 9)
            return n;
        sort(freq.begin(), freq.end(), greater<int>());
        int ans = 0, adder = 1, counter = 0;
        for (int i = 0; i < 26; i++, counter++)
        {
            if (freq[i] == 0)
                break;
            if (counter == 8)
            {
                adder++;
                counter = 0;
            }
            ans += freq[i] * adder;
        }
        return ans;
    }
};