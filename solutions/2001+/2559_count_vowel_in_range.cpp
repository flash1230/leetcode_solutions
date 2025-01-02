/* https://leetcode.com/problems/count-vowel-strings-in-ranges/
2559. Count Vowel Strings in Ranges
Medium
Prefix Sum
*/
class Solution
{
public:
    bool isVowel(char c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
    vector<int> vowelStrings(vector<string> &words, vector<vector<int>> &queries)
    {
        vector<int> nums;
        if (isVowel(words[0].front()) && isVowel(words[0].back()))
            nums.push_back(1);
        else
            nums.push_back(0);
        for (int i = 1; i < words.size(); i++)
        {
            if (isVowel(words[i].front()) && isVowel(words[i].back()))
                nums.push_back(nums.back() + 1);
            else
                nums.push_back(nums.back());
        }
        vector<int> ans;
        for (auto q : queries)
        {
            if (q[0] == 0)
                ans.push_back(nums[q[1]]);
            else
                ans.push_back(nums[q[1]] - nums[q[0] - 1]);
        }
        return ans;
    }
};