/* https://leetcode.com/problems/excel-sheet-column-title/
168. Excel Sheet Column Title
Easy
Math
*/
class Solution
{
public:
    string convertToTitle(int columnNumber)
    {
        string res;
        char tmp;
        while (columnNumber)
        {
            columnNumber -= 1;
            tmp = 'A' + columnNumber % 26;
            res = tmp + res;
            columnNumber /= 26;
        }
        return res;
    }
};