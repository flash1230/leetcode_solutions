/* https://leetcode.com/problems/roman-to-integer
13. Roman to Integer
Easy
*/
class Solution
{
public:
    int romanToInt(string s)
    {
        int n = s.length();
        int i = 0;
        int res = 0;
        while (i < n)
        {
            switch (s[i])
            {
            case 'M':
                res += 1000;
                i++;
                break;
            case 'D':
                res += 500;
                i++;
                break;
            case 'C':
                if (i < n - 1 && s[i + 1] == 'M')
                {
                    res += 900;
                    i = i + 2;
                    break;
                }
                else if (i < n - 1 && s[i + 1] == 'D')
                {
                    res += 400;
                    i += 2;
                    break;
                }
                else
                {
                    res += 100;
                    i++;
                    break;
                }
            case 'L':
                res += 50;
                i++;
                break;
            case 'X':
                if (i < n - 1 && s[i + 1] == 'L')
                {
                    res += 40;
                    i = i + 2;
                    break;
                }
                else if (i < n - 1 && s[i + 1] == 'C')
                {
                    res += 90;
                    i += 2;
                    break;
                }
                else
                {
                    res += 10;
                    i++;
                    break;
                }
            case 'V':
                res += 5;
                i++;
                break;
            case 'I':
                if (i < n - 1 && s[i + 1] == 'V')
                {
                    res += 4;
                    i = i + 2;
                    break;
                }
                else if (i < n - 1 && s[i + 1] == 'X')
                {
                    res += 9;
                    i += 2;
                    break;
                }
                else
                {
                    res += 1;
                    i++;
                    break;
                }
            default:
                break;
            }
        }
        return res;
    }
};