/* https://leetcode.com/problems/fraction-addition-and-subtraction/
592. Fraction Addition and Subtraction
Medium
*/
class Solution
{
public:
    vector<int> evaluate(int l1, int l2, int r1, int r2, char sign)
    {
        if (sign == '-')
            r1 = -r1;
        vector<int> ans(2);
        if (l1 == 0)
        {
            ans[0] = r1;
            ans[1] = r2;
        }
        else if (r1 == 0)
        {
            ans[0] = l1;
            ans[1] = l2;
        }
        else
        {
            ans[1] = lcm(l2, r2);
            ans[0] = l1 * (ans[1] / l2) + r1 * (ans[1] / r2);
        }
        return ans;
    }
    string fractionAddition(string expression)
    {
        int n = expression.length(), i = 0, left_n, left_d, right_n = INT_MAX, right_d;
        string temp;
        char sign;
        for (;; i++)
        {
            if (expression[i] == '/')
                break;
            temp += expression[i];
        }
        i++;
        left_n = stoi(temp);
        temp = "";
        temp += expression[i];
        i++;
        for (;; i++)
        {
            if (i == n || expression[i] == '+' || expression[i] == '-')
                break;
            temp += expression[i];
        }
        left_d = stoi(temp);
        if (left_d < 0 && left_n < 0)
        {
            left_d = abs(left_d);
            left_n = abs(left_n);
        }
        if (i == n)
        {
            int x = __gcd(abs(left_n), left_d);
            string ans;
            if (left_n < 0)
                ans += '-';
            ans += to_string(abs(left_n) / x);
            ans += '/';
            ans += to_string(left_d / x);
            return ans;
        }
        sign = expression[i];
        i++;
        temp = "";
        temp += expression[i];
        i++;
        for (; i <= n; i++)
        {
            if (right_n != INT_MAX)
            {
                if (i == n || expression[i] == '+' || expression[i] == '-')
                {
                    right_d = stoi(temp);
                    temp = "";
                    if (right_d < 0 && right_n < 0)
                    {
                        right_d = abs(right_d);
                        right_n = abs(right_n);
                    }
                    vector<int> bleh = evaluate(left_n, left_d, right_n, right_d, sign);
                    left_n = bleh[0];
                    left_d = bleh[1];
                    right_n = INT_MAX;
                    if (i != n)
                        sign = expression[i];
                }
                else
                    temp += expression[i];
            }
            else
            {
                if (expression[i] == '/')
                {
                    right_n = stoi(temp);
                    temp = "";
                    i++;
                    temp += expression[i];
                }
                else
                    temp += expression[i];
            }
        }
        int x = __gcd(abs(left_n), left_d);
        string ans;
        if (left_n < 0)
            ans += '-';
        ans += to_string(abs(left_n) / x);
        ans += '/';
        ans += to_string(left_d / x);
        return ans;
    }
};