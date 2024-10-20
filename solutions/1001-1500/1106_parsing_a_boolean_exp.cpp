/* https://leetcode.com/problems/parsing-a-boolean-expression/
1106. Parsing A Boolean Expression
Hard
Stack
*/
class Solution
{
public:
    char solve(string s, char op)
    {
        switch (op)
        {
        case '&':
            for (char c : s)
            {
                if (c == 'f')
                    return 'f';
            }
            return 't';
        case '|':
            for (char c : s)
            {
                if (c == 't')
                    return 't';
            }
            return 'f';
        case '!':
            return s[0] == 't' ? 'f' : 't';
        default:
            break;
        }
        return '9';
    }
    bool parseBoolExpr(string expression)
    {
        stack<char> mahstack;
        int i = 0;
        while (i < expression.size())
        {
            if (expression[i] != ')')
                mahstack.push(expression[i]);
            else if(expression[i]==',')
            {}
            else
            {
                string exp;
                char op;
                while (mahstack.top() != '(')
                {
                    exp += mahstack.top();
                    mahstack.pop();
                }
                mahstack.pop();
                op = mahstack.top();
                mahstack.pop();
                mahstack.push(solve(exp, op));
            }
            i++;
        }
        return mahstack.top() == 't' ? true : false;
    }
};