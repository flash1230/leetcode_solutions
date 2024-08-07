/* https://leetcode.com/problems/integer-to-english-words/
273. Integer to English Words
Hard
*/
class Solution
{
public:
    string ones[20] = {"", " One", " Two", " Three", " Four", " Five",
                       " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve",
                       " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen",
                       " Eighteen", " Nineteen"};
    string tens[10] = {"", "", " Twenty", " Thirty", " Forty",
                       " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    string getThreeDigit(int num)
    {
        string res = "";
        int n = num / 100;
        if (n > 0)
        {
            num = num % 100;
            res += ones[n];
            res += " Hundred";
        }
        if (num < 20)
            res += ones[num];
        else
        {
            n = num / 10;
            res += tens[n];
            res += ones[num % 10];
        }
        return res;
    }
    string numberToWords(int num)
    {
        if (num == 0)
            return "Zero";
        string ans = "";
        int n = num / 1000000000;
        num = num % 1000000000;
        if (n > 0)
        {
            ans += getThreeDigit(n);
            ans += " Billion";
        }
        n = num / 1000000;
        num = num % 1000000;
        if (n > 0)
        {
            ans += getThreeDigit(n);
            ans += " Million";
        }
        n = num / 1000;
        num = num % 1000;
        if (n > 0)
        {
            ans += getThreeDigit(n);
            ans += " Thousand";
        }
        ans += getThreeDigit(num);
        return ans.substr(1, ans.length());
    }
};