/* https://leetcode.com/problems/string-compression-iii/
3163. String Compression III
Medium
*/
class Solution
{
public:
    string compressedString(string word)
    {
        string ans;
        int count = 1;
        char c = word[0];
        for (int i = 1; i < word.length(); i++)
        {
            if (word[i] != c)
            {
                ans += to_string(count);
                ans += c;
                c = word[i];
                count = 1;
            }
            else
            {
                count++;
                if (count == 10)
                {
                    ans += '9';
                    ans += c;
                    count = 1;
                }
            }
        }
        ans += to_string(count);
        ans += c;
        return ans;
    }
};